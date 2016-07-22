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


void OutputDebugStringXA(const char *text1,const char *text2) {
	char buf[2048];
	wsprintfA(buf,"%s%s",text1,text2);
	OutputDebugStringA(buf);
};

void OutputDebugStringXW(const wchar_t *text1,const wchar_t *text2) {
	wchar_t buf[2048];
	wsprintfW(buf,L"%s%s",text1,text2);
	OutputDebugStringW(buf);
};

void OutputDebugStringZA(const char *text1,HMODULE hmodule,const char *text2) {
	char buf[2048];
	char buf2[2048];

	GetModuleFileName(hmodule,buf2,MAX_PATH);
	wsprintf(buf,"%s %s - %s",text1,buf2,text2);
	OutputDebugStringA(buf);
};

#include "libxyo-win-inject.hpp"

#include "dll-inject-sample-copyright.hpp"
#include "dll-inject-sample-licence.hpp"
#include "dll-inject-sample-version.hpp"

static char             thisModuleFileName[MAX_PATH];
static HINSTANCE        thisModule;
static int              loadedModulesSp;
static HMODULE          loadedModules[16384];
static void             thisHookInstance(HMODULE hInstance);

static XYO::Win::Inject::Hook::PGetProcAddress _original__GetProcAddress;
static FARPROC WINAPI hook_GetProcAddress(FARPROC retV,HMODULE hModule,LPCSTR lpProcName);

//
#include "new_kernel32.cpp"
#include "new_kernel32__CreateProcessA_99.cpp"
#include "new_kernel32__CreateProcessW_103.cpp"
#include "new_kernel32__GetProcAddress_408.cpp"
#include "new_kernel32__LoadLibraryA_578.cpp"
#include "new_kernel32__LoadLibraryExA_579.cpp"
#include "new_kernel32__LoadLibraryExW_580.cpp"
#include "new_kernel32__LoadLibraryW_581.cpp"
#include "new_kernel32__LoadModule_582.cpp"
#include "new_api-ms-win-core-processthreads-l1-1-2.cpp"
#include "new_api-ms-win-core-processthreads-l1-1-2__CreateProcessW_3.cpp"
#include "new_api-ms-win-core-libraryloader-l1-2-0.cpp"
#include "new_api-ms-win-core-libraryloader-l1-2-0__GetProcAddress_20.cpp"
#include "new_api-ms-win-core-libraryloader-l1-2-0__LoadLibraryExA_22.cpp"
#include "new_api-ms-win-core-libraryloader-l1-2-0__LoadLibraryExW_23.cpp"
#include "new_kernelbase.cpp"
#include "new_kernelbase__CreateProcessA_189.cpp"
#include "new_kernelbase__CreateProcessW_194.cpp"
#include "new_kernelbase__GetProcAddress_598.cpp"
#include "new_kernelbase__LoadLibraryA_892.cpp"
#include "new_kernelbase__LoadLibraryExA_893.cpp"
#include "new_kernelbase__LoadLibraryExW_894.cpp"
#include "new_kernelbase__LoadLibraryW_895.cpp"
//
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


FARPROC WINAPI hook_GetProcAddress(FARPROC retV,HMODULE hModule,LPCSTR lpProcName) {

#include "new_kernel32__GetProcAddress.cpp"
#include "new_kernelbase__GetProcAddress.cpp"
#include "new_api-ms-win-core-libraryloader-l1-2-0__GetProcAddress.cpp"
#include "new_api-ms-win-core-processthreads-l1-1-2__GetProcAddress.cpp"

#include "new_wininet__GetProcAddress.cpp"
#include "new_ws2_32__GetProcAddress.cpp"
#include "new_wsock32__GetProcAddress.cpp"

	return retV;
};

static LPSTR dllHookSkip[]= {
	"ICMP.DLL",
	"WS2_32.DLL",
	"WSOCK32.DLL",
	"NTDLL.DLL",
	"KERNEL32.DLL",
	"KERNELBASE.DLL",
	NULL
};

static BOOL WINAPI thisEnumImportModuleName(PVOID userData,LPSTR module) {
	HMODULE hModule;

	userData;
	hModule=GetModuleHandle(module);
	if(hModule!=NULL) {
		//OutputDebugStringXA("#import-original: ",module);
		//char buf[MAX_PATH];
		//GetModuleFileName(hModule,buf,MAX_PATH);
		//OutputDebugStringXA("#import-handle: ",buf);
		thisHookInstance(hModule);
	} else {
		OutputDebugStringXA("#import-null: ",module);
	};
	return TRUE;
};

static void thisHookInstanceProcess(HMODULE hInstance,BOOL mode) {
	//
	// kernel
	//
	_replace_kernel32__CreateProcessA_99 (hInstance,mode);
	_replace_kernel32__CreateProcessW_103(hInstance,mode);
	_replace_kernel32__LoadLibraryA_578  (hInstance,mode);
	_replace_kernel32__LoadLibraryExA_579(hInstance,mode);
	_replace_kernel32__LoadLibraryExW_580(hInstance,mode);
	_replace_kernel32__LoadLibraryW_581  (hInstance,mode);
	_replace_kernel32__LoadModule_582    (hInstance,mode);
	//
	_replace_kernel32__GetProcAddress_408(hInstance,mode);
	//
	//
	_replace_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExA_22(hInstance,mode);
	_replace_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExW_23(hInstance,mode);
	_replace_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress_20(hInstance,mode);
	//
	_replace_api_ms_win_core_processthreads_l1_1_2__CreateProcessW_3(hInstance,mode);
	//
	_replace_kernelbase__CreateProcessA_189(hInstance,mode);
	_replace_kernelbase__CreateProcessW_194(hInstance,mode);
	_replace_kernelbase__LoadLibraryA_892(hInstance,mode);
	_replace_kernelbase__LoadLibraryExA_893(hInstance,mode);
	_replace_kernelbase__LoadLibraryExW_894(hInstance,mode);
	_replace_kernelbase__LoadLibraryW_895(hInstance,mode);
	_replace_kernelbase__GetProcAddress_598(hInstance,mode);

	//
	// Other
	//

	_replace_wsock32__connect_4(hInstance,mode);
	_replace_wsock32__recv_16(hInstance,mode);
	_replace_wsock32__send_19(hInstance,mode);
	_replace_wsock32__bind_2(hInstance,mode);

	_replace_wininet__InternetConnectA_229(hInstance,mode);
	_replace_wininet__InternetConnectW_230(hInstance,mode);
	_replace_wininet__InternetReadFile_272(hInstance,mode);

	//
	_replace_ws2_32__connect_4(hInstance,mode);
	_replace_ws2_32__WSAConnect_30(hInstance,mode);
	_replace_ws2_32__recv_16(hInstance,mode);
	_replace_ws2_32__send_19(hInstance,mode);
	_replace_ws2_32__bind_2(hInstance,mode);
};

static void thisHookInstance(HMODULE hInstance) {
	int n;
	char buf[MAX_PATH];

	if(hInstance==NULL) {
		return;
	}

	GetModuleFileName(hInstance,buf,MAX_PATH);
	//OutputDebugStringXA("#hook: ",buf);

	for(n=0; n<loadedModulesSp; ++n) {
		if(loadedModules[n]==hInstance) {
			//OutputDebugStringXA("#loaded: ",buf);
			return;
		}
	};
	loadedModules[loadedModulesSp]=hInstance;
	if(loadedModulesSp<16380) {
		++loadedModulesSp;
	};

	for(n=0; dllHookSkip[n]!=NULL; ++n) {
		if(hInstance==GetModuleHandle(dllHookSkip[n])) {
			//OutputDebugStringXA("#skip: ",buf);
			return;
		};
	};

	thisHookInstanceProcess(hInstance,true);
	thisHookInstanceProcess(hInstance,false);

	OutputDebugStringXA("#hook-ok: ",buf);

	XYO::Win::Inject::Hook::enumImportTable(hInstance,thisEnumImportModuleName,NULL);
};

static BOOL isAttached=FALSE;
BOOL APIENTRY DllMain (HINSTANCE hInstance,DWORD reason,LPVOID reserved) {
	reserved;
	hInstance;
	switch(reason) {
		case DLL_PROCESS_ATTACH: {
				if(!isAttached) {
					//
					_original__GetProcAddress=GetProcAddress;
					//

					char processName[2048];
					GetModuleFileName(NULL,processName,2048);

					OutputDebugStringA("--- hookX1 ---");
					OutputDebugStringA(processName);

					DisableThreadLibraryCalls((HMODULE)hInstance);

					isAttached=TRUE;
					loadedModulesSp=0;
					thisModule=hInstance;
					GetModuleFileNameA(hInstance,thisModuleFileName,1020);

					_original_kernel32__GetProcAddress_408=GetProcAddress;
					_original_kernel32__LoadLibraryA_578=LoadLibraryA;
					_original_kernel32__LoadLibraryExA_579=LoadLibraryExA;
					_original_kernel32__LoadLibraryExW_580=LoadLibraryExW;
					_original_kernel32__LoadLibraryW_581=LoadLibraryW;
					//
					_original_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExA_22=LoadLibraryExA;
					_original_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExW_23=LoadLibraryExW;
					_original_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress_20=GetProcAddress;
					//
					_original_kernelbase__LoadLibraryA_892=LoadLibraryA;
					_original_kernelbase__LoadLibraryExA_893=LoadLibraryExA;
					_original_kernelbase__LoadLibraryExW_894=LoadLibraryExW;
					_original_kernelbase__LoadLibraryW_895=LoadLibraryW;
					_original_kernelbase__GetProcAddress_598=GetProcAddress;
					//

					OutputDebugStringA("--- imports ---");
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

