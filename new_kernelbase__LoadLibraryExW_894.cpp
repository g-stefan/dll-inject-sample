static HINSTANCE WINAPI _new_kernelbase__LoadLibraryExW_894(const wchar_t *lpLibFileName,HANDLE hFile,DWORD dwFlags) {
	HINSTANCE retV;

	//OutputDebugStringXW(L"kernel32_LoadLibraryExW:",lpLibFileName);

	retV=(*_original_kernelbase__LoadLibraryExW_894)(lpLibFileName,hFile,dwFlags);

	if(((dwFlags&DONT_RESOLVE_DLL_REFERENCES)!=DONT_RESOLVE_DLL_REFERENCES)&&
	   ((dwFlags&LOAD_LIBRARY_AS_DATAFILE)!=LOAD_LIBRARY_AS_DATAFILE)) {
		thisHookInstance(retV);
	};

	return retV;
};
