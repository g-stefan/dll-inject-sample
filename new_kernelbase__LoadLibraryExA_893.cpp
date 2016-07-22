static HINSTANCE WINAPI _new_kernelbase__LoadLibraryExA_893(const char *lpLibFileName,HANDLE hFile,DWORD dwFlags) {
	HINSTANCE retV;

	//OutputDebugStringXA("kernel32_LoadLibraryExA:",lpLibFileName);

	retV=(*_original_kernelbase__LoadLibraryExA_893)(lpLibFileName,hFile,dwFlags);

	if(((dwFlags&DONT_RESOLVE_DLL_REFERENCES)!=DONT_RESOLVE_DLL_REFERENCES)&&
	   ((dwFlags&LOAD_LIBRARY_AS_DATAFILE)!=LOAD_LIBRARY_AS_DATAFILE)) {
		thisHookInstance(retV);
	};

	return retV;
};
