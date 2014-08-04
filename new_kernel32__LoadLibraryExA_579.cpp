static HINSTANCE WINAPI _new_kernel32__LoadLibraryExA_579(const char *lpLibFileName,HANDLE hFile,DWORD dwFlags) {
	HINSTANCE retV;
	retV=(*_original_kernel32__LoadLibraryExA_579)(lpLibFileName,hFile,dwFlags);

	if(((dwFlags&DONT_RESOLVE_DLL_REFERENCES)!=DONT_RESOLVE_DLL_REFERENCES)&&
	   ((dwFlags&LOAD_LIBRARY_AS_DATAFILE)!=LOAD_LIBRARY_AS_DATAFILE)) {
		thisHookInstance(retV);
	};

	return retV;
};
