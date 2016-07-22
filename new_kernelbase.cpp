typedef BOOL (WINAPI *_ptr_kernelbase__CreateProcessA_189)(LPCTSTR lpApplicationName,LPTSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCTSTR lpCurrentDirectory,LPSTARTUPINFO lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
static _ptr_kernelbase__CreateProcessA_189 _original_kernelbase__CreateProcessA_189;
static BOOL WINAPI _new_kernelbase__CreateProcessA_189(LPCTSTR lpApplicationName,LPTSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCTSTR lpCurrentDirectory,LPSTARTUPINFO lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
static void _replace_kernelbase__CreateProcessA_189(HINSTANCE hInstance,BOOL mode) {
	_ptr_kernelbase__CreateProcessA_189 _function;
	if(hInstance!=GetModuleHandle("kernelbase.dll")) {
		_function=(_ptr_kernelbase__CreateProcessA_189)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernelbase__CreateProcessA_189,"kernelbase.dll","CreateProcessA",189,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_kernelbase__CreateProcessA_189)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernelbase__CreateProcessA_189,"kernelbase","CreateProcessA",189,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_kernelbase__CreateProcessA_189=_function;
		};
	};
};
typedef BOOL (WINAPI *_ptr_kernelbase__CreateProcessW_194)(LPCTSTR lpApplicationName,LPTSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCTSTR lpCurrentDirectory,LPSTARTUPINFO lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
static _ptr_kernelbase__CreateProcessW_194 _original_kernelbase__CreateProcessW_194;
static BOOL WINAPI _new_kernelbase__CreateProcessW_194(LPCTSTR lpApplicationName,LPTSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCTSTR lpCurrentDirectory,LPSTARTUPINFO lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
static void _replace_kernelbase__CreateProcessW_194(HINSTANCE hInstance,BOOL mode) {
	_ptr_kernelbase__CreateProcessW_194 _function;
	if(hInstance!=GetModuleHandle("kernelbase.dll")) {
		_function=(_ptr_kernelbase__CreateProcessW_194)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernelbase__CreateProcessW_194,"kernelbase.dll","CreateProcessW",194,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_kernelbase__CreateProcessW_194)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernelbase__CreateProcessW_194,"kernelbase","CreateProcessW",194,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_kernelbase__CreateProcessW_194=_function;
		};
	};
};
typedef HMODULE (WINAPI *_ptr_kernelbase__LoadLibraryA_892)(const char *lpFileName);
static _ptr_kernelbase__LoadLibraryA_892 _original_kernelbase__LoadLibraryA_892;
static HMODULE WINAPI _new_kernelbase__LoadLibraryA_892(const char *lpFileName);
static void _replace_kernelbase__LoadLibraryA_892(HINSTANCE hInstance,BOOL mode) {
	_ptr_kernelbase__LoadLibraryA_892 _function;
	if(hInstance!=GetModuleHandle("kernelbase.dll")) {
		_function=(_ptr_kernelbase__LoadLibraryA_892)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernelbase__LoadLibraryA_892,"kernelbase.dll","LoadLibraryA",892,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_kernelbase__LoadLibraryA_892)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernelbase__LoadLibraryA_892,"kernelbase","LoadLibraryA",892,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_kernelbase__LoadLibraryA_892=_function;
		};
	};
};
typedef HINSTANCE (WINAPI *_ptr_kernelbase__LoadLibraryExA_893)(const char *lpLibFileName,HANDLE hFile,DWORD dwFlags);
static _ptr_kernelbase__LoadLibraryExA_893 _original_kernelbase__LoadLibraryExA_893;
static HINSTANCE WINAPI _new_kernelbase__LoadLibraryExA_893(const char *lpLibFileName,HANDLE hFile,DWORD dwFlags);
static void _replace_kernelbase__LoadLibraryExA_893(HINSTANCE hInstance,BOOL mode) {
	_ptr_kernelbase__LoadLibraryExA_893 _function;
	if(hInstance!=GetModuleHandle("kernelbase.dll")) {
		_function=(_ptr_kernelbase__LoadLibraryExA_893)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernelbase__LoadLibraryExA_893,"kernelbase.dll","LoadLibraryExA",893,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_kernelbase__LoadLibraryExA_893)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernelbase__LoadLibraryExA_893,"kernelbase","LoadLibraryExA",893,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_kernelbase__LoadLibraryExA_893=_function;
		};
	};
};
typedef HINSTANCE (WINAPI *_ptr_kernelbase__LoadLibraryExW_894)(const wchar_t *lpLibFileName,HANDLE hFile,DWORD dwFlags);
static _ptr_kernelbase__LoadLibraryExW_894 _original_kernelbase__LoadLibraryExW_894;
static HINSTANCE WINAPI _new_kernelbase__LoadLibraryExW_894(const wchar_t *lpLibFileName,HANDLE hFile,DWORD dwFlags);
static void _replace_kernelbase__LoadLibraryExW_894(HINSTANCE hInstance,BOOL mode) {
	_ptr_kernelbase__LoadLibraryExW_894 _function;
	if(hInstance!=GetModuleHandle("kernelbase.dll")) {
		_function=(_ptr_kernelbase__LoadLibraryExW_894)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernelbase__LoadLibraryExW_894,"kernelbase.dll","LoadLibraryExW",894,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_kernelbase__LoadLibraryExW_894)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernelbase__LoadLibraryExW_894,"kernelbase","LoadLibraryExW",894,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_kernelbase__LoadLibraryExW_894=_function;
		};
	};
};
typedef HMODULE (WINAPI *_ptr_kernelbase__LoadLibraryW_895)(const wchar_t *lpFileName);
static _ptr_kernelbase__LoadLibraryW_895 _original_kernelbase__LoadLibraryW_895;
static HMODULE WINAPI _new_kernelbase__LoadLibraryW_895(const wchar_t *lpFileName);
static void _replace_kernelbase__LoadLibraryW_895(HINSTANCE hInstance,BOOL mode) {
	_ptr_kernelbase__LoadLibraryW_895 _function;
	if(hInstance!=GetModuleHandle("kernelbase.dll")) {
		_function=(_ptr_kernelbase__LoadLibraryW_895)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernelbase__LoadLibraryW_895,"kernelbase.dll","LoadLibraryW",895,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_kernelbase__LoadLibraryW_895)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernelbase__LoadLibraryW_895,"kernelbase","LoadLibraryW",895,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_kernelbase__LoadLibraryW_895=_function;
		};
	};
};
typedef FARPROC (WINAPI *_ptr_kernelbase__GetProcAddress_598)(HMODULE hModule,LPCSTR lpProcName);
static _ptr_kernelbase__GetProcAddress_598 _original_kernelbase__GetProcAddress_598;
static FARPROC WINAPI _new_kernelbase__GetProcAddress_598(HMODULE hModule,LPCSTR lpProcName);
static void _replace_kernelbase__GetProcAddress_598(HINSTANCE hInstance,BOOL mode) {
	_ptr_kernelbase__GetProcAddress_598 _function;
	if(hInstance!=GetModuleHandle("kernelbase.dll")) {
		_function=(_ptr_kernelbase__GetProcAddress_598)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernelbase__GetProcAddress_598,"kernelbase.dll","GetProcAddress",598,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_kernelbase__GetProcAddress_598)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernelbase__GetProcAddress_598,"kernelbase","GetProcAddress",598,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_kernelbase__GetProcAddress_598=_function;
		};
	};
};
