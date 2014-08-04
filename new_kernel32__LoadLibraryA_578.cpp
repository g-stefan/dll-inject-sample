static HMODULE WINAPI _new_kernel32__LoadLibraryA_578(const char *lpFileName) {
	HMODULE retV;
	retV=(*_original_kernel32__LoadLibraryA_578)(lpFileName);
	thisHookInstance(retV);
	return retV;
};
