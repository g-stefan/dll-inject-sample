if(retV!=nullptr) {
	if(GetModuleHandle("wsock32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,4))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"connect")==0))) {
			if(retV!=(FARPROC)_new_wsock32__connect_4) {
				_original_wsock32__connect_4=(_ptr_wsock32__connect_4)retV;
			};
			retV=(FARPROC)_new_wsock32__connect_4;
		};
	};
};
if(retV!=nullptr) {
	if(GetModuleHandle("wsock32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,16))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"recv")==0))) {
			if(retV!=(FARPROC)_new_wsock32__recv_16) {
				_original_wsock32__recv_16=(_ptr_wsock32__recv_16)retV;
			};
			retV=(FARPROC)_new_wsock32__recv_16;
		};
	};
};
if(retV!=nullptr) {
	if(GetModuleHandle("wsock32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,19))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"send")==0))) {
			if(retV!=(FARPROC)_new_wsock32__send_19) {
				_original_wsock32__send_19=(_ptr_wsock32__send_19)retV;
			};
			retV=(FARPROC)_new_wsock32__send_19;
		};
	};
};
if(retV!=nullptr) {
	if(GetModuleHandle("wsock32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,2))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"bind")==0))) {
			if(retV!=(FARPROC)_new_wsock32__bind_2) {
				_original_wsock32__bind_2=(_ptr_wsock32__bind_2)retV;
			};
			retV=(FARPROC)_new_wsock32__bind_2;
		};
	};
};
