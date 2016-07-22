@echo off
Set GEN=xyo-generate-hook.exe

del /F /Q new_kernel32.cpp
del /F /Q new_kernel32__GetProcAddress.cpp
%GEN% kernel32 WINAPI BOOL        99  CreateProcessA "LPCTSTR lpApplicationName,LPTSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCTSTR lpCurrentDirectory,LPSTARTUPINFO lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation"
%GEN% kernel32 WINAPI BOOL        103 CreateProcessW "LPCTSTR lpApplicationName,LPTSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCTSTR lpCurrentDirectory,LPSTARTUPINFO lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation"
%GEN% kernel32 WINAPI HMODULE     578 LoadLibraryA   "const char *lpFileName"
%GEN% kernel32 WINAPI HINSTANCE   579 LoadLibraryExA "const char *lpLibFileName,HANDLE hFile,DWORD dwFlags"
%GEN% kernel32 WINAPI HINSTANCE   580 LoadLibraryExW "const wchar_t *lpLibFileName,HANDLE hFile,DWORD dwFlags"
%GEN% kernel32 WINAPI HMODULE     581 LoadLibraryW   "const wchar_t *lpFileName"
%GEN% kernel32 WINAPI DWORD       582 LoadModule     "LPCSTR lpModuleName,LPVOID lpParameterBlock"
%GEN% kernel32 WINAPI FARPROC     408 GetProcAddress "HMODULE hModule,LPCSTR lpProcName"

del /F /Q new_api-ms-win-core-libraryloader-l1-2-0.cpp
del /F /Q new_api-ms-win-core-libraryloader-l1-2-0__GetProcAddress.cpp
%GEN% api-ms-win-core-libraryloader-l1-2-0 WINAPI HINSTANCE   22 LoadLibraryExA "const char *lpLibFileName,HANDLE hFile,DWORD dwFlags"
%GEN% api-ms-win-core-libraryloader-l1-2-0 WINAPI HINSTANCE   23 LoadLibraryExW "const wchar_t *lpLibFileName,HANDLE hFile,DWORD dwFlags"
%GEN% api-ms-win-core-libraryloader-l1-2-0 WINAPI FARPROC     20 GetProcAddress "HMODULE hModule,LPCSTR lpProcName"

del /F /Q new_api-ms-win-core-processthreads-l1-1-2.cpp
del /F /Q new_api-ms-win-core-processthreads-l1-1-2__GetProcAddress.cpp
%GEN% api-ms-win-core-processthreads-l1-1-2 WINAPI BOOL        3 CreateProcessW "LPCTSTR lpApplicationName,LPTSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCTSTR lpCurrentDirectory,LPSTARTUPINFO lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation"

del /F /Q new_kernelbase.cpp
del /F /Q new_kernelbase__GetProcAddress.cpp
%GEN% kernelbase WINAPI BOOL        189 CreateProcessA "LPCTSTR lpApplicationName,LPTSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCTSTR lpCurrentDirectory,LPSTARTUPINFO lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation"
%GEN% kernelbase WINAPI BOOL        194 CreateProcessW "LPCTSTR lpApplicationName,LPTSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCTSTR lpCurrentDirectory,LPSTARTUPINFO lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation"
%GEN% kernelbase WINAPI HMODULE     892 LoadLibraryA   "const char *lpFileName"
%GEN% kernelbase WINAPI HINSTANCE   893 LoadLibraryExA "const char *lpLibFileName,HANDLE hFile,DWORD dwFlags"
%GEN% kernelbase WINAPI HINSTANCE   894 LoadLibraryExW "const wchar_t *lpLibFileName,HANDLE hFile,DWORD dwFlags"
%GEN% kernelbase WINAPI HMODULE     895 LoadLibraryW   "const wchar_t *lpFileName"
%GEN% kernelbase WINAPI FARPROC     598 GetProcAddress "HMODULE hModule,LPCSTR lpProcName"

rem -----------------------------------------------------------------------------------------------

del /F /Q new_wsock32.cpp
del /F /Q new_wsock32__GetProcAddress.cpp
%GEN% wsock32 WSAAPI int 4  connect "SOCKET s, const struct sockaddr *addr, int sz"
%GEN% wsock32 WSAAPI int 16 recv    "SOCKET s, char* buf,int len,int flags"
%GEN% wsock32 WSAAPI int 19 send    "SOCKET s,const char* buf,int len,int flags"
%GEN% wsock32 WSAAPI int 2  bind    "SOCKET s, const struct sockaddr *addr, int sz"

del /F /Q new_wininet.cpp
del /F /Q new_wininet__GetProcAddress.cpp
%GEN% wininet STDAPICALLTYPE HINTERNET 229 InternetConnectA "HINTERNET hInternet,LPCTSTR lpszServerName,INTERNET_PORT nServerPort,LPCTSTR lpszUsername,LPCTSTR lpszPassword,DWORD dwService,DWORD dwFlags,DWORD_PTR dwContext"
%GEN% wininet STDAPICALLTYPE HINTERNET 230 InternetConnectW "HINTERNET hInternet,WCHAR * lpszServerName,INTERNET_PORT nServerPort,WCHAR * lpszUsername,WCHAR * lpszPassword,DWORD dwService,DWORD dwFlags,DWORD_PTR dwContext"
%GEN% wininet STDAPICALLTYPE BOOL      272 InternetReadFile "HINTERNET hFile,LPVOID lpBuffer,DWORD dwNumberOfBytesToRead,LPDWORD lpdwNumberOfBytesRead"

del /F /Q new_ws2_32.cpp
del /F /Q new_ws2_32__GetProcAddress.cpp
%GEN% ws2_32 WSAAPI int 4  connect    "SOCKET s,const struct sockaddr *addr,int sz"
%GEN% ws2_32 WSAAPI int 16 recv       "SOCKET s, char* buf,int len,int flags"
%GEN% ws2_32 WSAAPI int 30 WSAConnect "SOCKET s,const struct sockaddr *name,int namelen,void * lpCallerData,void * lpCalleeData,void * lpSQOS,void * lpGQOS"
%GEN% ws2_32 WSAAPI int 19 send       "SOCKET s,const char* buf,int len,int flags"
%GEN% ws2_32 WSAAPI int 2  bind       "SOCKET s, const struct sockaddr *addr, int sz"

