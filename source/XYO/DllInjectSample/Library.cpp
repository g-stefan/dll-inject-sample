// Dll Inject Sample
// Copyright (c) 2022 Grigore Stefan <g_stefan@yahoo.com>
// MIT License (MIT) <http://opensource.org/licenses/MIT>
// SPDX-FileCopyrightText: 2022 Grigore Stefan <g_stefan@yahoo.com>
// SPDX-License-Identifier: MIT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SECURITY_WIN32
#	define SECURITY_WIN32
#endif

#include <winsock2.h>
#include <windows.h>
#include <objbase.h>
#include <iads.h>
#include <adshlp.h>
#include <wininet.h>
#include <Iptypes.h>
#include <Iphlpapi.h>
#include <Security.h>
#include <ole2.h>
#include <shlobj.h>
#include <Shobjidl.h>
#include <docobj.h>
#include <mshtml.h>
#include <MsHtmHst.h>
#include <exdisp.h>
#include <exdispid.h>
#include <servprov.h>

#include <XYO/DllInjectSample/Library.hpp>
#include <XYO/DllInjectSample/Copyright.hpp>
#include <XYO/DllInjectSample/License.hpp>
#include <XYO/DllInjectSample/Version.hpp>

static void OutputDebugStringXA(const char *text1, const char *text2) {
	char buf[2048];
	wsprintfA(buf, "%s%s", text1, text2);
	OutputDebugStringA(buf);
};

static void OutputDebugStringXW(const wchar_t *text1, const wchar_t *text2) {
	wchar_t buf[2048];
	wsprintfW(buf, L"%s%s", text1, text2);
	OutputDebugStringW(buf);
};

static void OutputDebugStringZA(const char *text1, HMODULE hmodule, const char *text2) {
	char buf[2048];
	char buf2[2048];

	GetModuleFileName(hmodule, buf2, MAX_PATH);
	wsprintf(buf, "%s %s - %s", text1, buf2, text2);
	OutputDebugStringA(buf);
};

static char thisProcessFileName[MAX_PATH];
static char thisModuleFileName[MAX_PATH];
static HINSTANCE thisModule;
static size_t loadedModulesSp;
static HMODULE loadedModules[16384];
static void thisHookInstance(HMODULE hInstance);
static DWORD tlsIndex;
//
typedef struct SHookProcess {

		// WSARecv
		LPWSABUF WSARecv_lpBuffers;
		DWORD WSARecv_dwBufferCount;
		LPWSAOVERLAPPED WSARecv_lpOverlapped;

		// WSASend
		LPWSABUF WSASend_lpBuffers;
		DWORD WSASend_dwBufferCount;
		LPWSAOVERLAPPED WSASend_lpOverlapped;

		//
		// FILE *recvLog;
		// FILE *sendLog;

} HookProcess;

static HookProcess *newHookProcess() {
	HookProcess *hookProcess = new HookProcess();
	//
	hookProcess->WSARecv_lpBuffers = nullptr;
	hookProcess->WSARecv_dwBufferCount = 0;
	hookProcess->WSARecv_lpOverlapped = nullptr;
	//
	hookProcess->WSASend_lpBuffers = nullptr;
	hookProcess->WSASend_dwBufferCount = 0;
	hookProcess->WSASend_lpOverlapped = nullptr;
	//
	//

	// char name[128];
	// wsprintf(name,"c:\\tmp\\recv-%p.bin",GetCurrentThreadId());
	// hookProcess->recvLog=fopen(name,"ab");
	// OutputDebugStringA(name);
	// wsprintf(name,"c:\\tmp\\send-%p.bin",GetCurrentThreadId());
	// hookProcess->sendLog=fopen(name,"ab");
	// OutputDebugStringA(name);
	return hookProcess;
};

static void deleteHookProcess(HookProcess *hookProcess) {
	//	fclose(hookProcess->recvLog);
	//	fclose(hookProcess->sendLog);
	delete hookProcess;
};

static void checkHookProcess(HookProcess *&hookProcess) {
	if (hookProcess == nullptr) {
		hookProcess = newHookProcess();
		TlsSetValue(tlsIndex, hookProcess);
	};
};

static HookProcess *getHookProcess() {
	HookProcess *hookProcess = ((HookProcess *)TlsGetValue(tlsIndex));
	if (hookProcess == nullptr) {
		hookProcess = newHookProcess();
		TlsSetValue(tlsIndex, hookProcess);
	};
	return hookProcess;
};

static void recvHookProcess(HookProcess *hookProcess, char *buf, size_t len) {
	checkHookProcess(hookProcess);

	// OutputDebugStringA("recvHookProcess");
	// fwrite(buf,1,len,hookProcess->recvLog);
	// fflush(hookProcess->recvLog);
};

static void sendHookProcess(HookProcess *hookProcess, const char *buf, size_t len) {
	checkHookProcess(hookProcess);

	// OutputDebugStringA("sendHookProcess");
	// fwrite(buf,1,len,hookProcess->sendLog);
	// fflush(hookProcess->recvLog);
};

typedef FARPROC(WINAPI *PGetProcAddress)(HMODULE hModule, LPCSTR lpProcName);
static FARPROC WINAPI hook_GetProcAddress(FARPROC originalPorc, HMODULE hModule, LPCSTR lpProcName);
//
#include "new_kernel32.cpp"
#include "new_kernel32___proc.cpp"
#include "new_api-ms-win-core-processthreads-l1-1-2.cpp"
#include "new_api-ms-win-core-processthreads-l1-1-2___proc.cpp"
#include "new_api-ms-win-core-libraryloader-l1-2-0.cpp"
#include "new_api-ms-win-core-libraryloader-l1-2-0___proc.cpp"
#include "new_kernelbase.cpp"
#include "new_kernelbase___proc.cpp"
//
#include "new_wininet.cpp"
#include "new_wininet___proc.cpp"
#include "new_ws2_32.cpp"
#include "new_ws2_32___proc.cpp"
#include "new_wsock32.cpp"
#include "new_wsock32___proc.cpp"
#include "new_advapi32.cpp"
#include "new_advapi32___proc.cpp"

static XYO::Win::Inject::Hook::HookProc *hookList[] = {
//
#include "new_kernel32___hookProc.cpp"
#include "new_kernelbase___hookProc.cpp"
#include "new_api-ms-win-core-libraryloader-l1-2-0___hookProc.cpp"
#include "new_api-ms-win-core-processthreads-l1-1-2___hookProc.cpp"
//
#include "new_wininet___hookProc.cpp"
#include "new_ws2_32___hookProc.cpp"
#include "new_wsock32___hookProc.cpp"
#include "new_advapi32___hookProc.cpp"
    //

    //
    nullptr};

static void setOriginalFunction(){
#include "new_kernel32___setOriginalFunction.cpp"
#include "new_kernelbase___setOriginalFunction.cpp"
#include "new_api-ms-win-core-libraryloader-l1-2-0___setOriginalFunction.cpp"
#include "new_api-ms-win-core-processthreads-l1-1-2___setOriginalFunction.cpp"
//
#include "new_wininet___setOriginalFunction.cpp"
#include "new_ws2_32___setOriginalFunction.cpp"
#include "new_wsock32___setOriginalFunction.cpp"
#include "new_advapi32___setOriginalFunction.cpp"
};

FARPROC WINAPI hook_GetProcAddress(FARPROC originalPorc, HMODULE hModule, LPCSTR lpProcName) {
	FARPROC retV;
	// retV=XYO::Win::Inject::Hook::getProcAddress(hModule,lpProcName,hookList);
	// if(retV!=nullptr){
	//       return retV;
	// };
	// return (*((PGetProcAddress)originalPorc))(hModule,lpProcName);

	retV = (*((PGetProcAddress)originalPorc))(hModule, lpProcName);

	// OutputDebugStringA(lpProcName);

	XYO::Win::Inject::Hook::HookProc **scanList;
	for (scanList = hookList; *scanList != nullptr; ++scanList) {
		if (retV == (FARPROC)(*scanList)->originalProc) {
			OutputDebugStringA("---original---");
			OutputDebugStringA((*scanList)->procName);
			if (XYO::Encoding::StringCore::compareIgnoreCaseAscii((*scanList)->procName, "LoadLibraryW") == 0) {
				OutputDebugStringA("---replaced---");
				return (*scanList)->newProc;
			};
			if (XYO::Encoding::StringCore::compareIgnoreCaseAscii((*scanList)->procName, "LoadLibraryExW") == 0) {
				OutputDebugStringA("---replaced---");
				return (*scanList)->newProc;
			};
		};
		if (retV == (FARPROC)(*scanList)->newProc) {
			OutputDebugStringA("---new---");
			OutputDebugStringA((*scanList)->procName);
		};
	};

	return retV;
};

static LPSTR dllHookSkip[] = {
    "NTDLL.DLL",
    "KERNEL32.DLL",
    "KERNELBASE.DLL",
    "ICMP.DLL",
    "WININET.DLL",
    "WS2_32.DLL",
    "WSOCK32.DLL",
    NULL};

static void thisHookInstance(HMODULE hInstance) {
	if (XYO::Win::Inject::Hook::processModule(hInstance, hookList, loadedModules, loadedModulesSp, 16380, dllHookSkip)) {
		char buf[MAX_PATH];
		GetModuleFileName(hInstance, buf, MAX_PATH);
		OutputDebugStringXA("#hook: ", buf);
	};
};

static BOOL isAttached = FALSE;
BOOL APIENTRY DllMain(HINSTANCE hInstance, DWORD reason, LPVOID reserved) {
	reserved;
	hInstance;
	switch (reason) {
	case DLL_PROCESS_ATTACH: {
		// OutputDebugString("DLL_PROCESS_ATTACH");
		if (!isAttached) {
			isAttached = TRUE;
			loadedModulesSp = 0;
			thisModule = hInstance;
			GetModuleFileName(NULL, thisProcessFileName, MAX_PATH);
			GetModuleFileNameA(hInstance, thisModuleFileName, MAX_PATH);
			tlsIndex = TlsAlloc();
			if (tlsIndex == TLS_OUT_OF_INDEXES) {
				return FALSE;
			};
			setOriginalFunction();
			// DisableThreadLibraryCalls((HMODULE)hInstance);

			//

			OutputDebugStringA("--- hook ---");
			OutputDebugStringA(thisProcessFileName);
			OutputDebugStringA(thisModuleFileName);
			//
			OutputDebugStringA("--- imports ---");
			thisHookInstance(GetModuleHandle(NULL));
		};
		break;
	};
	    break;
	case DLL_PROCESS_DETACH: {
		// OutputDebugString("DLL_PROCESS_DETACH");
		TlsFree(tlsIndex);
	};
	    break;
	case DLL_THREAD_ATTACH: {
		// OutputDebugString("DLL_THREAD_ATTACH");
		TlsSetValue(tlsIndex, newHookProcess());
	};
	    break;
	case DLL_THREAD_DETACH: {
		// OutputDebugString("DLL_THREAD_DETACH");
		deleteHookProcess((HookProcess *)TlsGetValue(tlsIndex));
	};
	    break;
	};
	return TRUE;
};
