typedef BOOL (WINAPI *_ptr_kernel32__CreateProcessA_99)(LPCTSTR lpApplicationName,LPTSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCTSTR lpCurrentDirectory,LPSTARTUPINFO lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
static _ptr_kernel32__CreateProcessA_99 _original_kernel32__CreateProcessA_99;
static BOOL WINAPI _new_kernel32__CreateProcessA_99(LPCTSTR lpApplicationName,LPTSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCTSTR lpCurrentDirectory,LPSTARTUPINFO lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
static void _replace_kernel32__CreateProcessA_99(HINSTANCE hInstance,BOOL mode) {
	_ptr_kernel32__CreateProcessA_99 _function;
	if(hInstance!=GetModuleHandle("kernel32.dll")) {
		_function=(_ptr_kernel32__CreateProcessA_99)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernel32__CreateProcessA_99,"kernel32.dll","CreateProcessA",99,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_kernel32__CreateProcessA_99)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernel32__CreateProcessA_99,"kernel32","CreateProcessA",99,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_kernel32__CreateProcessA_99=_function;
		};
	};
};
typedef BOOL (WINAPI *_ptr_kernel32__CreateProcessW_103)(LPCTSTR lpApplicationName,LPTSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCTSTR lpCurrentDirectory,LPSTARTUPINFO lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
static _ptr_kernel32__CreateProcessW_103 _original_kernel32__CreateProcessW_103;
static BOOL WINAPI _new_kernel32__CreateProcessW_103(LPCTSTR lpApplicationName,LPTSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCTSTR lpCurrentDirectory,LPSTARTUPINFO lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
static void _replace_kernel32__CreateProcessW_103(HINSTANCE hInstance,BOOL mode) {
	_ptr_kernel32__CreateProcessW_103 _function;
	if(hInstance!=GetModuleHandle("kernel32.dll")) {
		_function=(_ptr_kernel32__CreateProcessW_103)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernel32__CreateProcessW_103,"kernel32.dll","CreateProcessW",103,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_kernel32__CreateProcessW_103)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernel32__CreateProcessW_103,"kernel32","CreateProcessW",103,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_kernel32__CreateProcessW_103=_function;
		};
	};
};
typedef HMODULE (WINAPI *_ptr_kernel32__LoadLibraryA_578)(const char *lpFileName);
static _ptr_kernel32__LoadLibraryA_578 _original_kernel32__LoadLibraryA_578;
static HMODULE WINAPI _new_kernel32__LoadLibraryA_578(const char *lpFileName);
static void _replace_kernel32__LoadLibraryA_578(HINSTANCE hInstance,BOOL mode) {
	_ptr_kernel32__LoadLibraryA_578 _function;
	if(hInstance!=GetModuleHandle("kernel32.dll")) {
		_function=(_ptr_kernel32__LoadLibraryA_578)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernel32__LoadLibraryA_578,"kernel32.dll","LoadLibraryA",578,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_kernel32__LoadLibraryA_578)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernel32__LoadLibraryA_578,"kernel32","LoadLibraryA",578,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_kernel32__LoadLibraryA_578=_function;
		};
	};
};
typedef HINSTANCE (WINAPI *_ptr_kernel32__LoadLibraryExA_579)(const char *lpLibFileName,HANDLE hFile,DWORD dwFlags);
static _ptr_kernel32__LoadLibraryExA_579 _original_kernel32__LoadLibraryExA_579;
static HINSTANCE WINAPI _new_kernel32__LoadLibraryExA_579(const char *lpLibFileName,HANDLE hFile,DWORD dwFlags);
static void _replace_kernel32__LoadLibraryExA_579(HINSTANCE hInstance,BOOL mode) {
	_ptr_kernel32__LoadLibraryExA_579 _function;
	if(hInstance!=GetModuleHandle("kernel32.dll")) {
		_function=(_ptr_kernel32__LoadLibraryExA_579)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernel32__LoadLibraryExA_579,"kernel32.dll","LoadLibraryExA",579,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_kernel32__LoadLibraryExA_579)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernel32__LoadLibraryExA_579,"kernel32","LoadLibraryExA",579,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_kernel32__LoadLibraryExA_579=_function;
		};
	};
};
typedef HINSTANCE (WINAPI *_ptr_kernel32__LoadLibraryExW_580)(const wchar_t *lpLibFileName,HANDLE hFile,DWORD dwFlags);
static _ptr_kernel32__LoadLibraryExW_580 _original_kernel32__LoadLibraryExW_580;
static HINSTANCE WINAPI _new_kernel32__LoadLibraryExW_580(const wchar_t *lpLibFileName,HANDLE hFile,DWORD dwFlags);
static void _replace_kernel32__LoadLibraryExW_580(HINSTANCE hInstance,BOOL mode) {
	_ptr_kernel32__LoadLibraryExW_580 _function;
	if(hInstance!=GetModuleHandle("kernel32.dll")) {
		_function=(_ptr_kernel32__LoadLibraryExW_580)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernel32__LoadLibraryExW_580,"kernel32.dll","LoadLibraryExW",580,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_kernel32__LoadLibraryExW_580)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernel32__LoadLibraryExW_580,"kernel32","LoadLibraryExW",580,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_kernel32__LoadLibraryExW_580=_function;
		};
	};
};
typedef HMODULE (WINAPI *_ptr_kernel32__LoadLibraryW_581)(const wchar_t *lpFileName);
static _ptr_kernel32__LoadLibraryW_581 _original_kernel32__LoadLibraryW_581;
static HMODULE WINAPI _new_kernel32__LoadLibraryW_581(const wchar_t *lpFileName);
static void _replace_kernel32__LoadLibraryW_581(HINSTANCE hInstance,BOOL mode) {
	_ptr_kernel32__LoadLibraryW_581 _function;
	if(hInstance!=GetModuleHandle("kernel32.dll")) {
		_function=(_ptr_kernel32__LoadLibraryW_581)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernel32__LoadLibraryW_581,"kernel32.dll","LoadLibraryW",581,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_kernel32__LoadLibraryW_581)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernel32__LoadLibraryW_581,"kernel32","LoadLibraryW",581,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_kernel32__LoadLibraryW_581=_function;
		};
	};
};
typedef DWORD (WINAPI *_ptr_kernel32__LoadModule_582)(LPCSTR lpModuleName,LPVOID lpParameterBlock);
static _ptr_kernel32__LoadModule_582 _original_kernel32__LoadModule_582;
static DWORD WINAPI _new_kernel32__LoadModule_582(LPCSTR lpModuleName,LPVOID lpParameterBlock);
static void _replace_kernel32__LoadModule_582(HINSTANCE hInstance,BOOL mode) {
	_ptr_kernel32__LoadModule_582 _function;
	if(hInstance!=GetModuleHandle("kernel32.dll")) {
		_function=(_ptr_kernel32__LoadModule_582)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernel32__LoadModule_582,"kernel32.dll","LoadModule",582,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_kernel32__LoadModule_582)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernel32__LoadModule_582,"kernel32","LoadModule",582,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_kernel32__LoadModule_582=_function;
		};
	};
};
typedef FARPROC (WINAPI *_ptr_kernel32__GetProcAddress_408)(HMODULE hModule,LPCSTR lpProcName);
static _ptr_kernel32__GetProcAddress_408 _original_kernel32__GetProcAddress_408;
static FARPROC WINAPI _new_kernel32__GetProcAddress_408(HMODULE hModule,LPCSTR lpProcName);
static void _replace_kernel32__GetProcAddress_408(HINSTANCE hInstance,BOOL mode) {
	_ptr_kernel32__GetProcAddress_408 _function;
	if(hInstance!=GetModuleHandle("kernel32.dll")) {
		_function=(_ptr_kernel32__GetProcAddress_408)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernel32__GetProcAddress_408,"kernel32.dll","GetProcAddress",408,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_kernel32__GetProcAddress_408)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_kernel32__GetProcAddress_408,"kernel32","GetProcAddress",408,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_kernel32__GetProcAddress_408=_function;
		};
	};
};
