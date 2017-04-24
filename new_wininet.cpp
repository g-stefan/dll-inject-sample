typedef HINTERNET (STDAPICALLTYPE *_ptr_wininet__InternetConnectA)(HINTERNET hInternet,LPCTSTR lpszServerName,INTERNET_PORT nServerPort,LPCTSTR lpszUsername,LPCTSTR lpszPassword,DWORD dwService,DWORD dwFlags,DWORD_PTR dwContext);
static HINTERNET STDAPICALLTYPE _new_wininet__InternetConnectA(HINTERNET hInternet,LPCTSTR lpszServerName,INTERNET_PORT nServerPort,LPCTSTR lpszUsername,LPCTSTR lpszPassword,DWORD dwService,DWORD dwFlags,DWORD_PTR dwContext);
static XYO::Win::Inject::Hook::HookProc _hook_wininet__InternetConnectA;
#define _original_wininet__InternetConnectA ((_ptr_wininet__InternetConnectA)(_hook_wininet__InternetConnectA.originalProc))
typedef HINTERNET (STDAPICALLTYPE *_ptr_wininet__InternetConnectW)(HINTERNET hInternet,WCHAR *lpszServerName,INTERNET_PORT nServerPort,WCHAR *lpszUsername,WCHAR *lpszPassword,DWORD dwService,DWORD dwFlags,DWORD_PTR dwContext);
static HINTERNET STDAPICALLTYPE _new_wininet__InternetConnectW(HINTERNET hInternet,WCHAR *lpszServerName,INTERNET_PORT nServerPort,WCHAR *lpszUsername,WCHAR *lpszPassword,DWORD dwService,DWORD dwFlags,DWORD_PTR dwContext);
static XYO::Win::Inject::Hook::HookProc _hook_wininet__InternetConnectW;
#define _original_wininet__InternetConnectW ((_ptr_wininet__InternetConnectW)(_hook_wininet__InternetConnectW.originalProc))
typedef BOOL (STDAPICALLTYPE *_ptr_wininet__InternetReadFile)(HINTERNET hFile,LPVOID lpBuffer,DWORD dwNumberOfBytesToRead,LPDWORD lpdwNumberOfBytesRead);
static BOOL STDAPICALLTYPE _new_wininet__InternetReadFile(HINTERNET hFile,LPVOID lpBuffer,DWORD dwNumberOfBytesToRead,LPDWORD lpdwNumberOfBytesRead);
static XYO::Win::Inject::Hook::HookProc _hook_wininet__InternetReadFile;
#define _original_wininet__InternetReadFile ((_ptr_wininet__InternetReadFile)(_hook_wininet__InternetReadFile.originalProc))
