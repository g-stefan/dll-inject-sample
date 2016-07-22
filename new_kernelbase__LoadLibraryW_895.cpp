static HMODULE WINAPI _new_kernelbase__LoadLibraryW_895(const wchar_t *lpFileName) {
	HMODULE retV;
	retV=(*_original_kernelbase__LoadLibraryW_895)(lpFileName);

	thisHookInstance(retV);

	return retV;
};
