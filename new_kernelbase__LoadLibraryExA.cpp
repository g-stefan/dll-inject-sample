static HINSTANCE WINAPI _new_kernelbase__LoadLibraryExA(const char *lpLibFileName,HANDLE hFile,DWORD dwFlags) {
	HINSTANCE retV;

	//OutputDebugStringXA("kernel32.LoadLibraryExA:",lpLibFileName);

	retV=(*_original_kernelbase__LoadLibraryExA)(lpLibFileName,hFile,dwFlags);
	DWORD errCode=GetLastError();

	if(((dwFlags&DONT_RESOLVE_DLL_REFERENCES)!=DONT_RESOLVE_DLL_REFERENCES)&&
	   ((dwFlags&LOAD_LIBRARY_AS_DATAFILE)!=LOAD_LIBRARY_AS_DATAFILE)) {
		thisHookInstance(retV);
	};

	SetLastError(errCode);
	return retV;
};
