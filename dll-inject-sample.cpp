//
// Dll Inject Sample
//
// Copyright (c) 2014 Grigore Stefan, <g_stefan@yahoo.com>
// Created by Grigore Stefan <g_stefan@yahoo.com>
//
// The MIT License (MIT) <http://opensource.org/licenses/MIT>
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SECURITY_WIN32
#define SECURITY_WIN32
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


#include "libxyo-win-inject.hpp"

#include "dll-inject-sample-copyright.hpp"
#include "dll-inject-sample-licence.hpp"
#include "dll-inject-sample-version.hpp"

static char             thisModuleFileName[MAX_PATH];
static HINSTANCE        thisModule;
static int              loadedModulesSp;
static HMODULE          loadedModules[16384];
static void             thisHookInstance(HMODULE hInstance);

#include "new_kernel32.cpp"
#include "new_kernel32__CreateProcessA_99.cpp"
#include "new_kernel32__CreateProcessW_103.cpp"
#include "new_kernel32__LoadLibraryA_578.cpp"
#include "new_kernel32__LoadLibraryExA_579.cpp"
#include "new_kernel32__LoadLibraryExW_580.cpp"
#include "new_kernel32__LoadLibraryW_581.cpp"
#include "new_kernel32__LoadModule_582.cpp"
#include "new_wininet.cpp"
#include "new_wininet__InternetConnectA_229.cpp"
#include "new_wininet__InternetConnectW_230.cpp"
#include "new_wininet__InternetReadFile_272.cpp"
#include "new_ws2_32.cpp"
#include "new_ws2_32__connect_4.cpp"
#include "new_ws2_32__WSAConnect_30.cpp"
#include "new_ws2_32__recv_16.cpp"
#include "new_ws2_32__send_19.cpp"
#include "new_ws2_32__bind_2.cpp"
#include "new_wsock32.cpp"
#include "new_wsock32__connect_4.cpp"
#include "new_wsock32__recv_16.cpp"
#include "new_wsock32__send_19.cpp"
#include "new_wsock32__bind_2.cpp"

#include "new_kernel32__GetProcAddress_408.cpp"

static LPSTR dllIcmp="ICMP.DLL";
static LPSTR dllWs2_32="WS2_32.DLL";
static LPSTR dllWsck32="WSCK32.DLL";
static LPSTR dllNtdll="NTDLL.DLL";
static LPSTR dllKernel32="KERNEL32.DLL";
static LPSTR dllKernelbase="KERNELBASE.DLL";
static LPSTR dllOleacc="OLEACC.DLL";
static LPSTR dllWs2help="WS2HELP.DLL";
static LPSTR dllPsapi="PSAPI.DLL";

static BOOL WINAPI thisEnumImportModuleName(PVOID userData,LPSTR module) {
	HMODULE hModule;

	userData;
	hModule=GetModuleHandle(module);
	if(hModule!=NULL) {
		thisHookInstance(hModule);
	};
	return TRUE;
};

static void thisHookInstance(HMODULE hInstance) {
	int n;
	char buf[MAX_PATH];
	if(hInstance==NULL) {
		return;
	}
	GetModuleFileName(hInstance,buf,MAX_PATH);

	for(n=0; n<loadedModulesSp; ++n) {
		if(loadedModules[n]==hInstance) {
			return;
		}
	};
	loadedModules[loadedModulesSp]=hInstance;
	if(loadedModulesSp<16380) {
		++loadedModulesSp;
	};

	//OutputDebugString(buf);

	if(hInstance==GetModuleHandle(dllIcmp)) {
		return;
	}
	if(hInstance==GetModuleHandle(dllNtdll)) {
		return;
	}
	if(hInstance==GetModuleHandle(dllKernel32)) {
		return;
	}
	if(hInstance==GetModuleHandle(dllWs2help)) {
		return;
	}
	if(hInstance==GetModuleHandle(dllWs2_32)) {
		return;
	}
	//if(hInstance==GetModuleHandle(dllKernelbase))return;
	//if(hInstance==GetModuleHandle(dllOleacc))return;
	//if(hInstance==GetModuleHandle(dllPsapi))return;

	OutputDebugString(buf);

	_replace_kernel32__CreateProcessA_99 (hInstance);
	_replace_kernel32__CreateProcessW_103(hInstance);
	_replace_kernel32__LoadLibraryA_578  (hInstance);
	_replace_kernel32__LoadLibraryExA_579(hInstance);
	_replace_kernel32__LoadLibraryExW_580(hInstance);
	_replace_kernel32__LoadLibraryW_581  (hInstance);
	_replace_kernel32__LoadModule_582    (hInstance);

	_replace_kernel32__GetProcAddress_408(hInstance);

	_replace_wsock32__connect_4(hInstance);
	_replace_wsock32__recv_16(hInstance);
	_replace_wsock32__send_19(hInstance);
	_replace_wsock32__bind_2(hInstance);

	_replace_ws2_32__connect_4(hInstance);
	_replace_ws2_32__WSAConnect_30(hInstance);
	_replace_ws2_32__recv_16(hInstance);
	_replace_ws2_32__send_19(hInstance);
	_replace_ws2_32__bind_2(hInstance);

	_replace_wininet__InternetConnectA_229(hInstance);
	_replace_wininet__InternetConnectW_230(hInstance);
	_replace_wininet__InternetReadFile_272(hInstance);

	XYO::Win::Inject::Hook::enumImportTable(hInstance,thisEnumImportModuleName,NULL);
};

static BOOL isAttached=FALSE;
BOOL APIENTRY DllMain (HINSTANCE hInstance,DWORD reason,LPVOID reserved) {
	reserved;
	hInstance;
	switch(reason) {
		case DLL_PROCESS_ATTACH: {
				//OutputDebugString("");
				if(!isAttached) {
					//DisableThreadLibraryCalls((HMODULE)hInstance);

					isAttached=TRUE;
					loadedModulesSp=0;
					thisModule=hInstance;
					GetModuleFileNameA(hInstance,thisModuleFileName,1020);

					_original_kernel32__GetProcAddress_408=GetProcAddress;
					_original_kernel32__LoadLibraryA_578=LoadLibraryA;
					_original_kernel32__LoadLibraryExA_579=LoadLibraryExA;
					_original_kernel32__LoadLibraryExW_580=LoadLibraryExW;
					_original_kernel32__LoadLibraryW_581=LoadLibraryW;

					thisHookInstance(GetModuleHandle(NULL));
				};
				break;
			};
			break;
		case DLL_PROCESS_DETACH: {
				//OutputDebugString("");
			};
			break;
		case DLL_THREAD_ATTACH: {
				//OutputDebugString("");
			};
			break;
		case DLL_THREAD_DETACH: {
				//OutputDebugString("");
			};
			break;
	};
	return TRUE;
};

