static HMODULE WINAPI _new_kernelbase__LoadLibraryA_892(const char *lpFileName) {
	HMODULE retV;
	retV=(*_original_kernelbase__LoadLibraryA_892)(lpFileName);

	thisHookInstance(retV);

	return retV;
};
