static HINSTANCE WINAPI _new_kernelbase__LoadLibraryExW(const wchar_t *lpLibFileName,HANDLE hFile,DWORD dwFlags) {
	HINSTANCE retV;

	//OutputDebugStringXW(L"kernel32.LoadLibraryExW:",lpLibFileName);

	retV=(*_original_kernelbase__LoadLibraryExW)(lpLibFileName,hFile,dwFlags);
	DWORD errCode=GetLastError();

	if(((dwFlags&DONT_RESOLVE_DLL_REFERENCES)!=DONT_RESOLVE_DLL_REFERENCES)&&
	   ((dwFlags&LOAD_LIBRARY_AS_DATAFILE)!=LOAD_LIBRARY_AS_DATAFILE)) {
		thisHookInstance(retV);
	};

	SetLastError(errCode);
	return retV;
};
