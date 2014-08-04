static FARPROC WINAPI _new_kernel32__GetProcAddress_408(HMODULE hModule,LPCSTR lpProcName) {
	FARPROC retV=NULL;

#include "new_kernel32__GetProcAddress.cpp"

	retV=(*_original_kernel32__GetProcAddress_408)(hModule,lpProcName);
	return retV;
};
