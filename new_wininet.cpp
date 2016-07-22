typedef HINTERNET (STDAPICALLTYPE *_ptr_wininet__InternetConnectA_229)(HINTERNET hInternet,LPCTSTR lpszServerName,INTERNET_PORT nServerPort,LPCTSTR lpszUsername,LPCTSTR lpszPassword,DWORD dwService,DWORD dwFlags,DWORD_PTR dwContext);
static _ptr_wininet__InternetConnectA_229 _original_wininet__InternetConnectA_229;
static HINTERNET STDAPICALLTYPE _new_wininet__InternetConnectA_229(HINTERNET hInternet,LPCTSTR lpszServerName,INTERNET_PORT nServerPort,LPCTSTR lpszUsername,LPCTSTR lpszPassword,DWORD dwService,DWORD dwFlags,DWORD_PTR dwContext);
static void _replace_wininet__InternetConnectA_229(HINSTANCE hInstance,BOOL mode) {
	_ptr_wininet__InternetConnectA_229 _function;
	if(hInstance!=GetModuleHandle("wininet.dll")) {
		_function=(_ptr_wininet__InternetConnectA_229)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_wininet__InternetConnectA_229,"wininet.dll","InternetConnectA",229,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_wininet__InternetConnectA_229)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_wininet__InternetConnectA_229,"wininet","InternetConnectA",229,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_wininet__InternetConnectA_229=_function;
		};
	};
};
typedef HINTERNET (STDAPICALLTYPE *_ptr_wininet__InternetConnectW_230)(HINTERNET hInternet,WCHAR *lpszServerName,INTERNET_PORT nServerPort,WCHAR *lpszUsername,WCHAR *lpszPassword,DWORD dwService,DWORD dwFlags,DWORD_PTR dwContext);
static _ptr_wininet__InternetConnectW_230 _original_wininet__InternetConnectW_230;
static HINTERNET STDAPICALLTYPE _new_wininet__InternetConnectW_230(HINTERNET hInternet,WCHAR *lpszServerName,INTERNET_PORT nServerPort,WCHAR *lpszUsername,WCHAR *lpszPassword,DWORD dwService,DWORD dwFlags,DWORD_PTR dwContext);
static void _replace_wininet__InternetConnectW_230(HINSTANCE hInstance,BOOL mode) {
	_ptr_wininet__InternetConnectW_230 _function;
	if(hInstance!=GetModuleHandle("wininet.dll")) {
		_function=(_ptr_wininet__InternetConnectW_230)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_wininet__InternetConnectW_230,"wininet.dll","InternetConnectW",230,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_wininet__InternetConnectW_230)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_wininet__InternetConnectW_230,"wininet","InternetConnectW",230,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_wininet__InternetConnectW_230=_function;
		};
	};
};
typedef BOOL (STDAPICALLTYPE *_ptr_wininet__InternetReadFile_272)(HINTERNET hFile,LPVOID lpBuffer,DWORD dwNumberOfBytesToRead,LPDWORD lpdwNumberOfBytesRead);
static _ptr_wininet__InternetReadFile_272 _original_wininet__InternetReadFile_272;
static BOOL STDAPICALLTYPE _new_wininet__InternetReadFile_272(HINTERNET hFile,LPVOID lpBuffer,DWORD dwNumberOfBytesToRead,LPDWORD lpdwNumberOfBytesRead);
static void _replace_wininet__InternetReadFile_272(HINSTANCE hInstance,BOOL mode) {
	_ptr_wininet__InternetReadFile_272 _function;
	if(hInstance!=GetModuleHandle("wininet.dll")) {
		_function=(_ptr_wininet__InternetReadFile_272)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_wininet__InternetReadFile_272,"wininet.dll","InternetReadFile",272,_original__GetProcAddress,mode);
		if(_function==nullptr) {
			_function=(_ptr_wininet__InternetReadFile_272)XYO::Win::Inject::Hook::replaceFunction(hInstance,(PROC)_new_wininet__InternetReadFile_272,"wininet","InternetReadFile",272,_original__GetProcAddress,mode);
		};
		if(_function!=nullptr) {
			_original_wininet__InternetReadFile_272=_function;
		};
	};
};
