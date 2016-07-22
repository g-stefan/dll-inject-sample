typedef BOOL (WINAPI *_ptr_api_ms_win_core_processthreads_l1_1_2__CreateProcessW_3)(LPCTSTR lpApplicationName,LPTSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCTSTR lpCurrentDirectory,LPSTARTUPINFO lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
static _ptr_api_ms_win_core_processthreads_l1_1_2__CreateProcessW_3 _original_api_ms_win_core_processthreads_l1_1_2__CreateProcessW_3;
static BOOL WINAPI _new_api_ms_win_core_processthreads_l1_1_2__CreateProcessW_3(LPCTSTR lpApplicationName,LPTSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCTSTR lpCurrentDirectory,LPSTARTUPINFO lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
static void _replace_api_ms_win_core_processthreads_l1_1_2__CreateProcessW_3(HINSTANCE hInstance,BOOL mode) {
	_ptr_api_ms_win_core_processthreads_l1_1_2__CreateProcessW_3 _function;
	if(hInstance!=GetModuleHandle("api-ms-win-core-processthreads-l1-1-2.dll")) {
		_function=(_ptr_api_ms_win_core_processthreads_l1_1_2__CreateProcessW_3)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_api_ms_win_core_processthreads_l1_1_2__CreateProcessW_3,"api-ms-win-core-processthreads-l1-1-2.dll","CreateProcessW",3,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_api_ms_win_core_processthreads_l1_1_2__CreateProcessW_3)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_api_ms_win_core_processthreads_l1_1_2__CreateProcessW_3,"api-ms-win-core-processthreads-l1-1-2","CreateProcessW",3,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_api_ms_win_core_processthreads_l1_1_2__CreateProcessW_3=_function;
		};
	};
};
