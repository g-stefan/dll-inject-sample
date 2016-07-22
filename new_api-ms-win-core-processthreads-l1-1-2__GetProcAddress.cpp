if(retV!=nullptr) {
	if(GetModuleHandle("api-ms-win-core-processthreads-l1-1-2.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,3))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"CreateProcessW")==0))) {
			if(retV!=(FARPROC)_new_api_ms_win_core_processthreads_l1_1_2__CreateProcessW_3) {
				_original_api_ms_win_core_processthreads_l1_1_2__CreateProcessW_3=(_ptr_api_ms_win_core_processthreads_l1_1_2__CreateProcessW_3)retV;
			};
			retV=(FARPROC)_new_api_ms_win_core_processthreads_l1_1_2__CreateProcessW_3;
		};
	};
};
