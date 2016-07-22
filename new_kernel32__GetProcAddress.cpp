if(retV!=nullptr) {
	if(GetModuleHandle("kernel32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,99))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"CreateProcessA")==0))) {
			if(retV!=(FARPROC)_new_kernel32__CreateProcessA_99) {
				_original_kernel32__CreateProcessA_99=(_ptr_kernel32__CreateProcessA_99)retV;
			};
			retV=(FARPROC)_new_kernel32__CreateProcessA_99;
		};
	};
};
if(retV!=nullptr) {
	if(GetModuleHandle("kernel32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,103))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"CreateProcessW")==0))) {
			if(retV!=(FARPROC)_new_kernel32__CreateProcessW_103) {
				_original_kernel32__CreateProcessW_103=(_ptr_kernel32__CreateProcessW_103)retV;
			};
			retV=(FARPROC)_new_kernel32__CreateProcessW_103;
		};
	};
};
if(retV!=nullptr) {
	if(GetModuleHandle("kernel32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,578))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"LoadLibraryA")==0))) {
			if(retV!=(FARPROC)_new_kernel32__LoadLibraryA_578) {
				_original_kernel32__LoadLibraryA_578=(_ptr_kernel32__LoadLibraryA_578)retV;
			};
			retV=(FARPROC)_new_kernel32__LoadLibraryA_578;
		};
	};
};
if(retV!=nullptr) {
	if(GetModuleHandle("kernel32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,579))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"LoadLibraryExA")==0))) {
			if(retV!=(FARPROC)_new_kernel32__LoadLibraryExA_579) {
				_original_kernel32__LoadLibraryExA_579=(_ptr_kernel32__LoadLibraryExA_579)retV;
			};
			retV=(FARPROC)_new_kernel32__LoadLibraryExA_579;
		};
	};
};
if(retV!=nullptr) {
	if(GetModuleHandle("kernel32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,580))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"LoadLibraryExW")==0))) {
			if(retV!=(FARPROC)_new_kernel32__LoadLibraryExW_580) {
				_original_kernel32__LoadLibraryExW_580=(_ptr_kernel32__LoadLibraryExW_580)retV;
			};
			retV=(FARPROC)_new_kernel32__LoadLibraryExW_580;
		};
	};
};
if(retV!=nullptr) {
	if(GetModuleHandle("kernel32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,581))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"LoadLibraryW")==0))) {
			if(retV!=(FARPROC)_new_kernel32__LoadLibraryW_581) {
				_original_kernel32__LoadLibraryW_581=(_ptr_kernel32__LoadLibraryW_581)retV;
			};
			retV=(FARPROC)_new_kernel32__LoadLibraryW_581;
		};
	};
};
if(retV!=nullptr) {
	if(GetModuleHandle("kernel32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,582))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"LoadModule")==0))) {
			if(retV!=(FARPROC)_new_kernel32__LoadModule_582) {
				_original_kernel32__LoadModule_582=(_ptr_kernel32__LoadModule_582)retV;
			};
			retV=(FARPROC)_new_kernel32__LoadModule_582;
		};
	};
};
if(retV!=nullptr) {
	if(GetModuleHandle("kernel32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,408))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"GetProcAddress")==0))) {
			if(retV!=(FARPROC)_new_kernel32__GetProcAddress_408) {
				_original_kernel32__GetProcAddress_408=(_ptr_kernel32__GetProcAddress_408)retV;
			};
			retV=(FARPROC)_new_kernel32__GetProcAddress_408;
		};
	};
};
