@echo off
rem Created by Grigore Stefan <g_stefan@yahoo.com>
rem Public domain (Unlicense) <http://unlicense.org>
rem SPDX-FileCopyrightText: 2022 Grigore Stefan <g_stefan@yahoo.com>
rem SPDX-License-Identifier: UnlicenseSet GEN=xyo-generate-hook.exe

pushd "source/XYO/DllInjectSample/Code"

del /F /Q new_kernel32.cpp
del /F /Q new_kernel32___setOriginalFunction.cpp
del /F /Q new_kernel32___hookProc.cpp
del /F /Q new_kernel32___proc.cpp
%GEN% kernel32 WINAPI BOOL        CreateProcessA "LPCTSTR lpApplicationName,LPTSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCTSTR lpCurrentDirectory,LPSTARTUPINFO lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation"
%GEN% kernel32 WINAPI BOOL        CreateProcessW "LPCTSTR lpApplicationName,LPTSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCTSTR lpCurrentDirectory,LPSTARTUPINFO lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation"
%GEN% kernel32 WINAPI HMODULE     LoadLibraryA   "const char *lpFileName"
%GEN% kernel32 WINAPI HINSTANCE   LoadLibraryExA "const char *lpLibFileName,HANDLE hFile,DWORD dwFlags"
%GEN% kernel32 WINAPI HINSTANCE   LoadLibraryExW "const wchar_t *lpLibFileName,HANDLE hFile,DWORD dwFlags"
%GEN% kernel32 WINAPI HMODULE     LoadLibraryW   "const wchar_t *lpFileName"
%GEN% kernel32 WINAPI DWORD       LoadModule     "LPCSTR lpModuleName,LPVOID lpParameterBlock"
%GEN% kernel32 WINAPI FARPROC     GetProcAddress "HMODULE hModule,LPCSTR lpProcName"

del /F /Q new_api-ms-win-core-libraryloader-l1-2-0.cpp
del /F /Q new_api-ms-win-core-libraryloader-l1-2-0___setOriginalFunction.cpp
del /F /Q new_api-ms-win-core-libraryloader-l1-2-0___hookProc.cpp
del /F /Q new_api-ms-win-core-libraryloader-l1-2-0___proc.cpp
%GEN% api-ms-win-core-libraryloader-l1-2-0 WINAPI HINSTANCE   LoadLibraryExA "const char *lpLibFileName,HANDLE hFile,DWORD dwFlags"
%GEN% api-ms-win-core-libraryloader-l1-2-0 WINAPI HINSTANCE   LoadLibraryExW "const wchar_t *lpLibFileName,HANDLE hFile,DWORD dwFlags"
%GEN% api-ms-win-core-libraryloader-l1-2-0 WINAPI FARPROC     GetProcAddress "HMODULE hModule,LPCSTR lpProcName"

del /F /Q new_api-ms-win-core-processthreads-l1-1-2.cpp
del /F /Q new_api-ms-win-core-processthreads-l1-1-2___setOriginalFunction.cpp
del /F /Q new_api-ms-win-core-processthreads-l1-1-2___hookProc.cpp
del /F /Q new_api-ms-win-core-processthreads-l1-1-2___proc.cpp
%GEN% api-ms-win-core-processthreads-l1-1-2 WINAPI BOOL       CreateProcessW "LPCTSTR lpApplicationName,LPTSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCTSTR lpCurrentDirectory,LPSTARTUPINFO lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation"

del /F /Q new_kernelbase.cpp
del /F /Q new_kernelbase___setOriginalFunction.cpp
del /F /Q new_kernelbase___hookProc.cpp
del /F /Q new_kernelbase___proc.cpp
%GEN% kernelbase WINAPI BOOL        CreateProcessA "LPCTSTR lpApplicationName,LPTSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCTSTR lpCurrentDirectory,LPSTARTUPINFO lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation"
%GEN% kernelbase WINAPI BOOL        CreateProcessW "LPCTSTR lpApplicationName,LPTSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCTSTR lpCurrentDirectory,LPSTARTUPINFO lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation"
%GEN% kernelbase WINAPI HMODULE     LoadLibraryA   "const char *lpFileName"
%GEN% kernelbase WINAPI HINSTANCE   LoadLibraryExA "const char *lpLibFileName,HANDLE hFile,DWORD dwFlags"
%GEN% kernelbase WINAPI HINSTANCE   LoadLibraryExW "const wchar_t *lpLibFileName,HANDLE hFile,DWORD dwFlags"
%GEN% kernelbase WINAPI HMODULE     LoadLibraryW   "const wchar_t *lpFileName"
%GEN% kernelbase WINAPI FARPROC     GetProcAddress "HMODULE hModule,LPCSTR lpProcName"

rem -----------------------------------------------------------------------------------------------

del /F /Q new_wsock32.cpp
del /F /Q new_wsock32___setOriginalFunction.cpp
del /F /Q new_wsock32___hookProc.cpp
del /F /Q new_wsock32___proc.cpp
%GEN% wsock32 WSAAPI int connect "SOCKET s, const struct sockaddr *addr, int sz"
%GEN% wsock32 WSAAPI int recv    "SOCKET s, char* buf,int len,int flags"
%GEN% wsock32 WSAAPI int send    "SOCKET s,const char* buf,int len,int flags"
%GEN% wsock32 WSAAPI int bind    "SOCKET s, const struct sockaddr *addr, int sz"

del /F /Q new_wininet.cpp
del /F /Q new_wininet___setOriginalFunction.cpp
del /F /Q new_wininet___hookProc.cpp
del /F /Q new_wininet___proc.cpp
%GEN% wininet STDAPICALLTYPE HINTERNET InternetConnectA "HINTERNET hInternet,LPCTSTR lpszServerName,INTERNET_PORT nServerPort,LPCTSTR lpszUsername,LPCTSTR lpszPassword,DWORD dwService,DWORD dwFlags,DWORD_PTR dwContext"
%GEN% wininet STDAPICALLTYPE HINTERNET InternetConnectW "HINTERNET hInternet,WCHAR * lpszServerName,INTERNET_PORT nServerPort,WCHAR * lpszUsername,WCHAR * lpszPassword,DWORD dwService,DWORD dwFlags,DWORD_PTR dwContext"
%GEN% wininet STDAPICALLTYPE BOOL      InternetReadFile "HINTERNET hFile,LPVOID lpBuffer,DWORD dwNumberOfBytesToRead,LPDWORD lpdwNumberOfBytesRead"

del /F /Q new_ws2_32.cpp
del /F /Q new_ws2_32___setOriginalFunction.cpp
del /F /Q new_ws2_32___hookProc.cpp
del /F /Q new_ws2_32___proc.cpp
%GEN% ws2_32 WSAAPI int connect    "SOCKET s,const struct sockaddr *addr,int sz"
%GEN% ws2_32 WSAAPI int recv       "SOCKET s, char* buf,int len,int flags"
%GEN% ws2_32 WSAAPI int WSAConnect "SOCKET s,const struct sockaddr *name,int namelen,void * lpCallerData,void * lpCalleeData,void * lpSQOS,void * lpGQOS"
%GEN% ws2_32 WSAAPI int send       "SOCKET s,const char* buf,int len,int flags"
%GEN% ws2_32 WSAAPI int bind       "SOCKET s, const struct sockaddr *addr, int sz"
%GEN% ws2_32 WSAAPI int WSARecv    "SOCKET s,LPWSABUF lpBuffers,DWORD dwBufferCount,LPDWORD lpNumberOfBytesRecvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine"
%GEN% ws2_32 WSAAPI int WSASend    "SOCKET s,LPWSABUF lpBuffers,DWORD dwBufferCount,LPDWORD lpNumberOfBytesSent,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine"
%GEN% ws2_32 WSAAPI BOOL WSAGetOverlappedResult "SOCKET s,LPWSAOVERLAPPED lpOverlapped,LPDWORD lpcbTransfer,BOOL fWait,LPDWORD lpdwFlags"

del /F /Q new_advapi32.cpp
del /F /Q new_advapi32___setOriginalFunction.cpp
del /F /Q new_advapi32___hookProc.cpp
del /F /Q new_advapi32___proc.cpp
%GEN% advapi32 WINAPI BOOL CreateProcessAsUserA "HANDLE hToken,LPCTSTR lpApplicationName,LPTSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCTSTR lpCurrentDirectory,LPSTARTUPINFO lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation"
%GEN% advapi32 WINAPI BOOL CreateProcessAsUserW "HANDLE hToken,LPCTSTR lpApplicationName,LPTSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCTSTR lpCurrentDirectory,LPSTARTUPINFO lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation"

popd
