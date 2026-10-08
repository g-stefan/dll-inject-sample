// Created by Grigore Stefan <g_stefan@yahoo.com>
// Public domain (Unlicense) <http://unlicense.org>
// SPDX-FileCopyrightText: 2014-2026 Grigore Stefan <g_stefan@yahoo.com>
// SPDX-License-Identifier: Unlicense

// Structural check of the built payload DLL.
//
// dll-inject-sample.dll is meant to be injected into a target process. The one
// invariant that injection cannot work without is bitness: a process can only
// load a DLL of its own architecture. This test reads the built DLL straight
// from disk (it never loads it, so DllMain never runs and nothing is hooked)
// and checks that it is a well-formed PE *DLL*, built for the same machine as
// this test executable, with an entry point (DllMain). A broken build, a
// non-DLL output, or a wrong-bitness build all fail here.

#include <XYO/WinInject.hpp>

#include <cstdio>
#include <stdexcept>
#include <string>
#include <vector>

static std::vector<unsigned char> readFile(const char *path) {
	std::vector<unsigned char> data;
	FILE *f = fopen(path, "rb");
	if (f == nullptr) {
		return data;
	};
	fseek(f, 0, SEEK_END);
	long size = ftell(f);
	fseek(f, 0, SEEK_SET);
	if (size > 0) {
		data.resize((size_t)size);
		size_t got = fread(data.data(), 1, (size_t)size, f);
		data.resize(got);
	};
	fclose(f);
	return data;
};

static std::string exeDir() {
	char buf[MAX_PATH];
	DWORD n = GetModuleFileNameA(nullptr, buf, MAX_PATH);
	std::string path(buf, (n > 0 && n < MAX_PATH) ? n : 0);
	size_t slash = path.find_last_of("\\/");
	if (slash == std::string::npos) {
		return std::string(".");
	};
	return path.substr(0, slash);
};

// Find dll-inject-sample.dll whether the test runs from output/test (the
// fabricare layout: ../bin), from output/bin, or from the repository root.
static std::string findDll() {
	std::string dir = exeDir();
	const char *candidates[] = {
	    "../bin/dll-inject-sample.dll",     // cwd = output/test (fabricare test)
	    "output/bin/dll-inject-sample.dll", // cwd = repository root
	    nullptr};
	std::string fromExe[] = {
	    dir + "\\dll-inject-sample.dll",
	    dir + "\\..\\bin\\dll-inject-sample.dll",
	    dir + "\\..\\..\\output\\bin\\dll-inject-sample.dll"};

	for (int i = 0; candidates[i] != nullptr; ++i) {
		if (GetFileAttributesA(candidates[i]) != INVALID_FILE_ATTRIBUTES) {
			return candidates[i];
		};
	};
	for (const std::string &p : fromExe) {
		if (GetFileAttributesA(p.c_str()) != INVALID_FILE_ATTRIBUTES) {
			return p;
		};
	};
	return std::string();
};

// Machine (IMAGE_FILE_MACHINE_*) of an already-mapped module, read from its
// in-memory PE headers.
static WORD machineOfModule(HMODULE hModule) {
	PIMAGE_DOS_HEADER dos = (PIMAGE_DOS_HEADER)hModule;
	if (dos->e_magic != IMAGE_DOS_SIGNATURE) {
		throw std::runtime_error("current module is not a PE image");
	};
	PIMAGE_NT_HEADERS nt = (PIMAGE_NT_HEADERS)((BYTE *)dos + dos->e_lfanew);
	if (nt->Signature != IMAGE_NT_SIGNATURE) {
		throw std::runtime_error("current module has no PE signature");
	};
	return nt->FileHeader.Machine;
};

void test() {
	std::string dllPath = findDll();
	if (dllPath.empty()) {
		throw std::runtime_error("dll-inject-sample.dll not found - run 'fabricare make' first");
	};
	printf("  dll: %s\r\n", dllPath.c_str());

	std::vector<unsigned char> image = readFile(dllPath.c_str());
	if (image.size() < sizeof(IMAGE_DOS_HEADER)) {
		throw std::runtime_error("DLL file too small / unreadable");
	};

	// DOS header
	PIMAGE_DOS_HEADER dos = (PIMAGE_DOS_HEADER)image.data();
	if (dos->e_magic != IMAGE_DOS_SIGNATURE) {
		throw std::runtime_error("missing MZ signature");
	};

	// NT headers (bounds-checked against the file size)
	if (dos->e_lfanew <= 0 || (size_t)dos->e_lfanew + sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER) > image.size()) {
		throw std::runtime_error("e_lfanew out of range");
	};
	DWORD signature = *(DWORD *)(image.data() + dos->e_lfanew);
	if (signature != IMAGE_NT_SIGNATURE) {
		throw std::runtime_error("missing PE signature");
	};
	PIMAGE_FILE_HEADER fileHeader = (PIMAGE_FILE_HEADER)(image.data() + dos->e_lfanew + sizeof(DWORD));

	// It must be a DLL.
	if ((fileHeader->Characteristics & IMAGE_FILE_DLL) == 0) {
		throw std::runtime_error("image is not marked IMAGE_FILE_DLL");
	};

	// Bitness must match this test executable (the injection invariant).
	WORD expected = machineOfModule(GetModuleHandleA(nullptr));
	if (fileHeader->Machine != expected) {
		char msg[128];
		sprintf(msg, "machine 0x%04X does not match this build's 0x%04X", fileHeader->Machine, expected);
		throw std::runtime_error(msg);
	};

	// It must have an entry point (DllMain). AddressOfEntryPoint sits at the
	// same offset in the 32- and 64-bit optional headers; since the machine
	// matched, IMAGE_NT_HEADERS has this build's layout.
	if ((size_t)dos->e_lfanew + sizeof(IMAGE_NT_HEADERS) > image.size()) {
		throw std::runtime_error("optional header out of range");
	};
	PIMAGE_NT_HEADERS nt = (PIMAGE_NT_HEADERS)(image.data() + dos->e_lfanew);
	if (nt->OptionalHeader.AddressOfEntryPoint == 0) {
		throw std::runtime_error("no entry point (DllMain)");
	};

	printf("  machine 0x%04X, DLL, entry point RVA 0x%08lX\r\n",
	    fileHeader->Machine, (unsigned long)nt->OptionalHeader.AddressOfEntryPoint);
	printf("Done.\r\n");
};

int main(int cmdN, char *cmdS[]) {
	try {
		test();
		return 0;
	} catch (const std::exception &e) {
		printf("* Error: %s\n", e.what());
	} catch (...) {
		printf("* Error: Unknown\n");
	};
	return 1;
};
