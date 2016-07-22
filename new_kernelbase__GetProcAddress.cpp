if(retV!=nullptr) {
	if(GetModuleHandle("kernelbase.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,189))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"CreateProcessA")==0))) {
			if(retV!=(FARPROC)_new_kernelbase__CreateProcessA_189) {
				_original_kernelbase__CreateProcessA_189=(_ptr_kernelbase__CreateProcessA_189)retV;
			};
			retV=(FARPROC)_new_kernelbase__CreateProcessA_189;
		};
	};
};
if(retV!=nullptr) {
	if(GetModuleHandle("kernelbase.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,194))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"CreateProcessW")==0))) {
			if(retV!=(FARPROC)_new_kernelbase__CreateProcessW_194) {
				_original_kernelbase__CreateProcessW_194=(_ptr_kernelbase__CreateProcessW_194)retV;
			};
			retV=(FARPROC)_new_kernelbase__CreateProcessW_194;
		};
	};
};
if(retV!=nullptr) {
	if(GetModuleHandle("kernelbase.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,892))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"LoadLibraryA")==0))) {
			if(retV!=(FARPROC)_new_kernelbase__LoadLibraryA_892) {
				_original_kernelbase__LoadLibraryA_892=(_ptr_kernelbase__LoadLibraryA_892)retV;
			};
			retV=(FARPROC)_new_kernelbase__LoadLibraryA_892;
		};
	};
};
if(retV!=nullptr) {
	if(GetModuleHandle("kernelbase.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,893))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"LoadLibraryExA")==0))) {
			if(retV!=(FARPROC)_new_kernelbase__LoadLibraryExA_893) {
				_original_kernelbase__LoadLibraryExA_893=(_ptr_kernelbase__LoadLibraryExA_893)retV;
			};
			retV=(FARPROC)_new_kernelbase__LoadLibraryExA_893;
		};
	};
};
if(retV!=nullptr) {
	if(GetModuleHandle("kernelbase.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,894))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"LoadLibraryExW")==0))) {
			if(retV!=(FARPROC)_new_kernelbase__LoadLibraryExW_894) {
				_original_kernelbase__LoadLibraryExW_894=(_ptr_kernelbase__LoadLibraryExW_894)retV;
			};
			retV=(FARPROC)_new_kernelbase__LoadLibraryExW_894;
		};
	};
};
if(retV!=nullptr) {
	if(GetModuleHandle("kernelbase.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,895))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"LoadLibraryW")==0))) {
			if(retV!=(FARPROC)_new_kernelbase__LoadLibraryW_895) {
				_original_kernelbase__LoadLibraryW_895=(_ptr_kernelbase__LoadLibraryW_895)retV;
			};
			retV=(FARPROC)_new_kernelbase__LoadLibraryW_895;
		};
	};
};
if(retV!=nullptr) {
	if(GetModuleHandle("kernelbase.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,598))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"GetProcAddress")==0))) {
			if(retV!=(FARPROC)_new_kernelbase__GetProcAddress_598) {
				_original_kernelbase__GetProcAddress_598=(_ptr_kernelbase__GetProcAddress_598)retV;
			};
			retV=(FARPROC)_new_kernelbase__GetProcAddress_598;
		};
	};
};
