// Created by Grigore Stefan <g_stefan@yahoo.com>
// Public domain (Unlicense) <http://unlicense.org>
// SPDX-FileCopyrightText: 2014-2026 Grigore Stefan <g_stefan@yahoo.com>
// SPDX-License-Identifier: Unlicense

// Version-stamp check of the built payload DLL.
//
// The build stamps version.json's numbers into the DLL's version resource
// (via Version.rh / Library.rc). This test reads that resource straight from
// the file with GetFileVersionInfo (no load, so DllMain never runs) and checks
// the FILEVERSION equals version + build from version.json. It catches a DLL
// that was built without, or with a stale, version resource.

#include <XYO/WinInject.hpp>

#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <string>

#pragma comment(lib, "version.lib")

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

static std::string firstExisting(const char *const *cwdRelative, const std::string *fromExe, size_t fromExeCount) {
	for (int i = 0; cwdRelative[i] != nullptr; ++i) {
		if (GetFileAttributesA(cwdRelative[i]) != INVALID_FILE_ATTRIBUTES) {
			return cwdRelative[i];
		};
	};
	for (size_t i = 0; i < fromExeCount; ++i) {
		if (GetFileAttributesA(fromExe[i].c_str()) != INVALID_FILE_ATTRIBUTES) {
			return fromExe[i];
		};
	};
	return std::string();
};

static std::string findDll() {
	std::string dir = exeDir();
	const char *cwdRelative[] = {"../bin/dll-inject-sample.dll", "output/bin/dll-inject-sample.dll", nullptr};
	std::string fromExe[] = {
	    dir + "\\dll-inject-sample.dll",
	    dir + "\\..\\bin\\dll-inject-sample.dll",
	    dir + "\\..\\..\\output\\bin\\dll-inject-sample.dll"};
	return firstExisting(cwdRelative, fromExe, 3);
};

static std::string findVersionJson() {
	std::string dir = exeDir();
	const char *cwdRelative[] = {"../../version.json", "version.json", nullptr};
	std::string fromExe[] = {dir + "\\..\\..\\version.json"};
	return firstExisting(cwdRelative, fromExe, 1);
};

static std::string fileText(const std::string &path) {
	std::string out;
	FILE *f = fopen(path.c_str(), "rb");
	if (f == nullptr) {
		return out;
	};
	char buf[4096];
	size_t n;
	while ((n = fread(buf, 1, sizeof(buf), f)) > 0) {
		out.append(buf, n);
	};
	fclose(f);
	return out;
};

// Return the string value of "key": "value" in a small JSON text, or "".
static std::string jsonStringValue(const std::string &text, const std::string &key) {
	std::string needle = "\"" + key + "\"";
	size_t at = text.find(needle);
	if (at == std::string::npos) {
		return std::string();
	};
	at = text.find(':', at + needle.size());
	if (at == std::string::npos) {
		return std::string();
	};
	size_t open = text.find('"', at);
	if (open == std::string::npos) {
		return std::string();
	};
	size_t close = text.find('"', open + 1);
	if (close == std::string::npos) {
		return std::string();
	};
	return text.substr(open + 1, close - open - 1);
};

void test() {
	std::string dllPath = findDll();
	if (dllPath.empty()) {
		throw std::runtime_error("dll-inject-sample.dll not found - run 'fabricare make' first");
	};
	std::string versionJsonPath = findVersionJson();
	if (versionJsonPath.empty()) {
		throw std::runtime_error("version.json not found");
	};

	// Expected numbers from version.json: "version" = "a.b.c", "build" = "d".
	std::string text = fileText(versionJsonPath);
	std::string version = jsonStringValue(text, "version");
	std::string build = jsonStringValue(text, "build");
	if (version.empty() || build.empty()) {
		throw std::runtime_error("could not read version/build from version.json");
	};
	unsigned a = 0, b = 0, c = 0, d = 0;
	if (sscanf(version.c_str(), "%u.%u.%u", &a, &b, &c) != 3) {
		throw std::runtime_error(std::string("malformed version: ") + version);
	};
	d = (unsigned)strtoul(build.c_str(), nullptr, 10);
	printf("  version.json: %u.%u.%u build %u\r\n", a, b, c, d);

	// FILEVERSION from the DLL's version resource (no load).
	DWORD handle = 0;
	DWORD size = GetFileVersionInfoSizeA(dllPath.c_str(), &handle);
	if (size == 0) {
		throw std::runtime_error("DLL has no version resource");
	};
	std::string info;
	info.resize(size);
	if (!GetFileVersionInfoA(dllPath.c_str(), handle, size, &info[0])) {
		throw std::runtime_error("GetFileVersionInfo failed");
	};
	VS_FIXEDFILEINFO *fixed = nullptr;
	UINT fixedLen = 0;
	if (!VerQueryValueA(&info[0], "\\", (LPVOID *)&fixed, &fixedLen) || fixed == nullptr) {
		throw std::runtime_error("VerQueryValue(root) failed");
	};
	if (fixed->dwSignature != 0xFEEF04BD) {
		throw std::runtime_error("bad VS_FIXEDFILEINFO signature");
	};

	unsigned fa = HIWORD(fixed->dwFileVersionMS);
	unsigned fb = LOWORD(fixed->dwFileVersionMS);
	unsigned fc = HIWORD(fixed->dwFileVersionLS);
	unsigned fd = LOWORD(fixed->dwFileVersionLS);
	printf("  DLL FILEVERSION: %u.%u.%u.%u\r\n", fa, fb, fc, fd);

	if (fa != a || fb != b || fc != c || fd != d) {
		char msg[160];
		sprintf(msg, "FILEVERSION %u.%u.%u.%u does not match version.json %u.%u.%u.%u",
		    fa, fb, fc, fd, a, b, c, d);
		throw std::runtime_error(msg);
	};

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
