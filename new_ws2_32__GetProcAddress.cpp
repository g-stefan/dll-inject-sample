if(retV!=nullptr) {
	if(GetModuleHandle("ws2_32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,4))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"connect")==0))) {
			if(retV!=(FARPROC)_new_ws2_32__connect_4) {
				_original_ws2_32__connect_4=(_ptr_ws2_32__connect_4)retV;
			};
			retV=(FARPROC)_new_ws2_32__connect_4;
		};
	};
};
if(retV!=nullptr) {
	if(GetModuleHandle("ws2_32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,16))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"recv")==0))) {
			if(retV!=(FARPROC)_new_ws2_32__recv_16) {
				_original_ws2_32__recv_16=(_ptr_ws2_32__recv_16)retV;
			};
			retV=(FARPROC)_new_ws2_32__recv_16;
		};
	};
};
if(retV!=nullptr) {
	if(GetModuleHandle("ws2_32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,30))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"WSAConnect")==0))) {
			if(retV!=(FARPROC)_new_ws2_32__WSAConnect_30) {
				_original_ws2_32__WSAConnect_30=(_ptr_ws2_32__WSAConnect_30)retV;
			};
			retV=(FARPROC)_new_ws2_32__WSAConnect_30;
		};
	};
};
if(retV!=nullptr) {
	if(GetModuleHandle("ws2_32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,19))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"send")==0))) {
			if(retV!=(FARPROC)_new_ws2_32__send_19) {
				_original_ws2_32__send_19=(_ptr_ws2_32__send_19)retV;
			};
			retV=(FARPROC)_new_ws2_32__send_19;
		};
	};
};
if(retV!=nullptr) {
	if(GetModuleHandle("ws2_32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,2))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"bind")==0))) {
			if(retV!=(FARPROC)_new_ws2_32__bind_2) {
				_original_ws2_32__bind_2=(_ptr_ws2_32__bind_2)retV;
			};
			retV=(FARPROC)_new_ws2_32__bind_2;
		};
	};
};
