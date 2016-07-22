if(retV!=nullptr) {
	if(GetModuleHandle("wininet.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,229))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"InternetConnectA")==0))) {
			if(retV!=(FARPROC)_new_wininet__InternetConnectA_229) {
				_original_wininet__InternetConnectA_229=(_ptr_wininet__InternetConnectA_229)retV;
			};
			retV=(FARPROC)_new_wininet__InternetConnectA_229;
		};
	};
};
if(retV!=nullptr) {
	if(GetModuleHandle("wininet.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,230))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"InternetConnectW")==0))) {
			if(retV!=(FARPROC)_new_wininet__InternetConnectW_230) {
				_original_wininet__InternetConnectW_230=(_ptr_wininet__InternetConnectW_230)retV;
			};
			retV=(FARPROC)_new_wininet__InternetConnectW_230;
		};
	};
};
if(retV!=nullptr) {
	if(GetModuleHandle("wininet.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,272))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"InternetReadFile")==0))) {
			if(retV!=(FARPROC)_new_wininet__InternetReadFile_272) {
				_original_wininet__InternetReadFile_272=(_ptr_wininet__InternetReadFile_272)retV;
			};
			retV=(FARPROC)_new_wininet__InternetReadFile_272;
		};
	};
};
