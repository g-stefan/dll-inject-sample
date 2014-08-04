if(retV!=NULL) {
	if(GetModuleHandle("kernel32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,99))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"CreateProcessA")==0))) {
			if(retV!=(FARPROC)_new_kernel32__CreateProcessA_99) {
				_original_kernel32__CreateProcessA_99=(_ptr_kernel32__CreateProcessA_99)retV;
			}
			retV=(FARPROC)_new_kernel32__CreateProcessA_99;
		};
	};
};
if(retV!=NULL) {
	if(GetModuleHandle("kernel32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,103))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"CreateProcessW")==0))) {
			if(retV!=(FARPROC)_new_kernel32__CreateProcessW_103) {
				_original_kernel32__CreateProcessW_103=(_ptr_kernel32__CreateProcessW_103)retV;
			}
			retV=(FARPROC)_new_kernel32__CreateProcessW_103;
		};
	};
};
if(retV!=NULL) {
	if(GetModuleHandle("kernel32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,578))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"LoadLibraryA")==0))) {
			if(retV!=(FARPROC)_new_kernel32__LoadLibraryA_578) {
				_original_kernel32__LoadLibraryA_578=(_ptr_kernel32__LoadLibraryA_578)retV;
			}
			retV=(FARPROC)_new_kernel32__LoadLibraryA_578;
		};
	};
};
if(retV!=NULL) {
	if(GetModuleHandle("kernel32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,579))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"LoadLibraryExA")==0))) {
			if(retV!=(FARPROC)_new_kernel32__LoadLibraryExA_579) {
				_original_kernel32__LoadLibraryExA_579=(_ptr_kernel32__LoadLibraryExA_579)retV;
			}
			retV=(FARPROC)_new_kernel32__LoadLibraryExA_579;
		};
	};
};
if(retV!=NULL) {
	if(GetModuleHandle("kernel32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,580))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"LoadLibraryExW")==0))) {
			if(retV!=(FARPROC)_new_kernel32__LoadLibraryExW_580) {
				_original_kernel32__LoadLibraryExW_580=(_ptr_kernel32__LoadLibraryExW_580)retV;
			}
			retV=(FARPROC)_new_kernel32__LoadLibraryExW_580;
		};
	};
};
if(retV!=NULL) {
	if(GetModuleHandle("kernel32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,581))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"LoadLibraryW")==0))) {
			if(retV!=(FARPROC)_new_kernel32__LoadLibraryW_581) {
				_original_kernel32__LoadLibraryW_581=(_ptr_kernel32__LoadLibraryW_581)retV;
			}
			retV=(FARPROC)_new_kernel32__LoadLibraryW_581;
		};
	};
};
if(retV!=NULL) {
	if(GetModuleHandle("kernel32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,582))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"LoadModule")==0))) {
			if(retV!=(FARPROC)_new_kernel32__LoadModule_582) {
				_original_kernel32__LoadModule_582=(_ptr_kernel32__LoadModule_582)retV;
			}
			retV=(FARPROC)_new_kernel32__LoadModule_582;
		};
	};
};
if(retV!=NULL) {
	if(GetModuleHandle("kernel32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,408))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"GetProcAddress")==0))) {
			if(retV!=(FARPROC)_new_kernel32__GetProcAddress_408) {
				_original_kernel32__GetProcAddress_408=(_ptr_kernel32__GetProcAddress_408)retV;
			}
			retV=(FARPROC)_new_kernel32__GetProcAddress_408;
		};
	};
};
if(retV!=NULL) {
	if(GetModuleHandle("wsock32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,4))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"connect")==0))) {
			if(retV!=(FARPROC)_new_wsock32__connect_4) {
				_original_wsock32__connect_4=(_ptr_wsock32__connect_4)retV;
			}
			retV=(FARPROC)_new_wsock32__connect_4;
		};
	};
};
if(retV!=NULL) {
	if(GetModuleHandle("wsock32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,16))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"recv")==0))) {
			if(retV!=(FARPROC)_new_wsock32__recv_16) {
				_original_wsock32__recv_16=(_ptr_wsock32__recv_16)retV;
			}
			retV=(FARPROC)_new_wsock32__recv_16;
		};
	};
};
if(retV!=NULL) {
	if(GetModuleHandle("wsock32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,19))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"send")==0))) {
			if(retV!=(FARPROC)_new_wsock32__send_19) {
				_original_wsock32__send_19=(_ptr_wsock32__send_19)retV;
			}
			retV=(FARPROC)_new_wsock32__send_19;
		};
	};
};
if(retV!=NULL) {
	if(GetModuleHandle("wsock32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,2))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"bind")==0))) {
			if(retV!=(FARPROC)_new_wsock32__bind_2) {
				_original_wsock32__bind_2=(_ptr_wsock32__bind_2)retV;
			}
			retV=(FARPROC)_new_wsock32__bind_2;
		};
	};
};
if(retV!=NULL) {
	if(GetModuleHandle("wininet.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,229))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"InternetConnectA")==0))) {
			if(retV!=(FARPROC)_new_wininet__InternetConnectA_229) {
				_original_wininet__InternetConnectA_229=(_ptr_wininet__InternetConnectA_229)retV;
			}
			retV=(FARPROC)_new_wininet__InternetConnectA_229;
		};
	};
};
if(retV!=NULL) {
	if(GetModuleHandle("wininet.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,230))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"InternetConnectW")==0))) {
			if(retV!=(FARPROC)_new_wininet__InternetConnectW_230) {
				_original_wininet__InternetConnectW_230=(_ptr_wininet__InternetConnectW_230)retV;
			}
			retV=(FARPROC)_new_wininet__InternetConnectW_230;
		};
	};
};
if(retV!=NULL) {
	if(GetModuleHandle("wininet.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,272))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"InternetReadFile")==0))) {
			if(retV!=(FARPROC)_new_wininet__InternetReadFile_272) {
				_original_wininet__InternetReadFile_272=(_ptr_wininet__InternetReadFile_272)retV;
			}
			retV=(FARPROC)_new_wininet__InternetReadFile_272;
		};
	};
};
if(retV!=NULL) {
	if(GetModuleHandle("ws2_32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,4))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"connect")==0))) {
			if(retV!=(FARPROC)_new_ws2_32__connect_4) {
				_original_ws2_32__connect_4=(_ptr_ws2_32__connect_4)retV;
			}
			retV=(FARPROC)_new_ws2_32__connect_4;
		};
	};
};
if(retV!=NULL) {
	if(GetModuleHandle("ws2_32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,16))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"recv")==0))) {
			if(retV!=(FARPROC)_new_ws2_32__recv_16) {
				_original_ws2_32__recv_16=(_ptr_ws2_32__recv_16)retV;
			}
			retV=(FARPROC)_new_ws2_32__recv_16;
		};
	};
};
if(retV!=NULL) {
	if(GetModuleHandle("ws2_32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,30))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"WSAConnect")==0))) {
			if(retV!=(FARPROC)_new_ws2_32__WSAConnect_30) {
				_original_ws2_32__WSAConnect_30=(_ptr_ws2_32__WSAConnect_30)retV;
			}
			retV=(FARPROC)_new_ws2_32__WSAConnect_30;
		};
	};
};
if(retV!=NULL) {
	if(GetModuleHandle("ws2_32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,19))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"send")==0))) {
			if(retV!=(FARPROC)_new_ws2_32__send_19) {
				_original_ws2_32__send_19=(_ptr_ws2_32__send_19)retV;
			}
			retV=(FARPROC)_new_ws2_32__send_19;
		};
	};
};
if(retV!=NULL) {
	if(GetModuleHandle("ws2_32.dll")==hModule) {
		if((lpProcName==(LPCSTR)MAKELONG(0,2))
		   ||((HIWORD((DWORD)lpProcName)!=0)&&(lstrcmpiA(lpProcName,"bind")==0))) {
			if(retV!=(FARPROC)_new_ws2_32__bind_2) {
				_original_ws2_32__bind_2=(_ptr_ws2_32__bind_2)retV;
			}
			retV=(FARPROC)_new_ws2_32__bind_2;
		};
	};
};
