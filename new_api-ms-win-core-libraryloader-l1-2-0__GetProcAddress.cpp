if(retV!=nullptr) {
	if(GetModuleHandle("api-ms-win-core-libraryloader-l1-2-0.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,22))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"LoadLibraryExA")==0))) {
			if(retV!=(FARPROC)_new_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExA_22) {
				_original_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExA_22=(_ptr_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExA_22)retV;
			};
			retV=(FARPROC)_new_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExA_22;
		};
	};
};
if(retV!=nullptr) {
	if(GetModuleHandle("api-ms-win-core-libraryloader-l1-2-0.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,23))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"LoadLibraryExW")==0))) {
			if(retV!=(FARPROC)_new_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExW_23) {
				_original_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExW_23=(_ptr_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExW_23)retV;
			};
			retV=(FARPROC)_new_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExW_23;
		};
	};
};
if(retV!=nullptr) {
	if(GetModuleHandle("api-ms-win-core-libraryloader-l1-2-0.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,20))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"GetProcAddress")==0))) {
			if(retV!=(FARPROC)_new_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress_20) {
				_original_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress_20=(_ptr_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress_20)retV;
			};
			retV=(FARPROC)_new_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress_20;
		};
	};
};
