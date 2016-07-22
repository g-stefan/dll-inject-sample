typedef HINSTANCE (WINAPI *_ptr_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExA_22)(const char *lpLibFileName,HANDLE hFile,DWORD dwFlags);
static _ptr_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExA_22 _original_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExA_22;
static HINSTANCE WINAPI _new_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExA_22(const char *lpLibFileName,HANDLE hFile,DWORD dwFlags);
static void _replace_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExA_22(HINSTANCE hInstance,BOOL mode) {
	_ptr_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExA_22 _function;
	if(hInstance!=GetModuleHandle("api-ms-win-core-libraryloader-l1-2-0.dll")) {
		_function=(_ptr_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExA_22)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExA_22,"api-ms-win-core-libraryloader-l1-2-0.dll","LoadLibraryExA",22,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExA_22)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExA_22,"api-ms-win-core-libraryloader-l1-2-0","LoadLibraryExA",22,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExA_22=_function;
		};
	};
};
typedef HINSTANCE (WINAPI *_ptr_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExW_23)(const wchar_t *lpLibFileName,HANDLE hFile,DWORD dwFlags);
static _ptr_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExW_23 _original_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExW_23;
static HINSTANCE WINAPI _new_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExW_23(const wchar_t *lpLibFileName,HANDLE hFile,DWORD dwFlags);
static void _replace_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExW_23(HINSTANCE hInstance,BOOL mode) {
	_ptr_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExW_23 _function;
	if(hInstance!=GetModuleHandle("api-ms-win-core-libraryloader-l1-2-0.dll")) {
		_function=(_ptr_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExW_23)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExW_23,"api-ms-win-core-libraryloader-l1-2-0.dll","LoadLibraryExW",23,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExW_23)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExW_23,"api-ms-win-core-libraryloader-l1-2-0","LoadLibraryExW",23,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExW_23=_function;
		};
	};
};
typedef FARPROC (WINAPI *_ptr_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress_20)(HMODULE hModule,LPCSTR lpProcName);
static _ptr_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress_20 _original_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress_20;
static FARPROC WINAPI _new_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress_20(HMODULE hModule,LPCSTR lpProcName);
static void _replace_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress_20(HINSTANCE hInstance,BOOL mode) {
	_ptr_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress_20 _function;
	if(hInstance!=GetModuleHandle("api-ms-win-core-libraryloader-l1-2-0.dll")) {
		_function=(_ptr_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress_20)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress_20,"api-ms-win-core-libraryloader-l1-2-0.dll","GetProcAddress",20,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress_20)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress_20,"api-ms-win-core-libraryloader-l1-2-0","GetProcAddress",20,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress_20=_function;
		};
	};
};
