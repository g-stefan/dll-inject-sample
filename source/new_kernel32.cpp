typedef BOOL (WINAPI *_ptr_kernel32__CreateProcessA)(LPCTSTR lpApplicationName, LPTSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCTSTR lpCurrentDirectory, LPSTARTUPINFO lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation);
static BOOL WINAPI _new_kernel32__CreateProcessA(LPCTSTR lpApplicationName, LPTSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCTSTR lpCurrentDirectory, LPSTARTUPINFO lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation);
static XYO::Win::Inject::Hook::HookProc _hook_kernel32__CreateProcessA;
#define _original_kernel32__CreateProcessA ((_ptr_kernel32__CreateProcessA)(_hook_kernel32__CreateProcessA.originalProc))
typedef BOOL (WINAPI *_ptr_kernel32__CreateProcessW)(LPCTSTR lpApplicationName, LPTSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCTSTR lpCurrentDirectory, LPSTARTUPINFO lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation);
static BOOL WINAPI _new_kernel32__CreateProcessW(LPCTSTR lpApplicationName, LPTSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCTSTR lpCurrentDirectory, LPSTARTUPINFO lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation);
static XYO::Win::Inject::Hook::HookProc _hook_kernel32__CreateProcessW;
#define _original_kernel32__CreateProcessW ((_ptr_kernel32__CreateProcessW)(_hook_kernel32__CreateProcessW.originalProc))
typedef HMODULE (WINAPI *_ptr_kernel32__LoadLibraryA)(const char *lpFileName);
static HMODULE WINAPI _new_kernel32__LoadLibraryA(const char *lpFileName);
static XYO::Win::Inject::Hook::HookProc _hook_kernel32__LoadLibraryA;
#define _original_kernel32__LoadLibraryA ((_ptr_kernel32__LoadLibraryA)(_hook_kernel32__LoadLibraryA.originalProc))
typedef HINSTANCE (WINAPI *_ptr_kernel32__LoadLibraryExA)(const char *lpLibFileName, HANDLE hFile, DWORD dwFlags);
static HINSTANCE WINAPI _new_kernel32__LoadLibraryExA(const char *lpLibFileName, HANDLE hFile, DWORD dwFlags);
static XYO::Win::Inject::Hook::HookProc _hook_kernel32__LoadLibraryExA;
#define _original_kernel32__LoadLibraryExA ((_ptr_kernel32__LoadLibraryExA)(_hook_kernel32__LoadLibraryExA.originalProc))
typedef HINSTANCE (WINAPI *_ptr_kernel32__LoadLibraryExW)(const wchar_t *lpLibFileName, HANDLE hFile, DWORD dwFlags);
static HINSTANCE WINAPI _new_kernel32__LoadLibraryExW(const wchar_t *lpLibFileName, HANDLE hFile, DWORD dwFlags);
static XYO::Win::Inject::Hook::HookProc _hook_kernel32__LoadLibraryExW;
#define _original_kernel32__LoadLibraryExW ((_ptr_kernel32__LoadLibraryExW)(_hook_kernel32__LoadLibraryExW.originalProc))
typedef HMODULE (WINAPI *_ptr_kernel32__LoadLibraryW)(const wchar_t *lpFileName);
static HMODULE WINAPI _new_kernel32__LoadLibraryW(const wchar_t *lpFileName);
static XYO::Win::Inject::Hook::HookProc _hook_kernel32__LoadLibraryW;
#define _original_kernel32__LoadLibraryW ((_ptr_kernel32__LoadLibraryW)(_hook_kernel32__LoadLibraryW.originalProc))
typedef DWORD (WINAPI *_ptr_kernel32__LoadModule)(LPCSTR lpModuleName, LPVOID lpParameterBlock);
static DWORD WINAPI _new_kernel32__LoadModule(LPCSTR lpModuleName, LPVOID lpParameterBlock);
static XYO::Win::Inject::Hook::HookProc _hook_kernel32__LoadModule;
#define _original_kernel32__LoadModule ((_ptr_kernel32__LoadModule)(_hook_kernel32__LoadModule.originalProc))
typedef FARPROC (WINAPI *_ptr_kernel32__GetProcAddress)(HMODULE hModule, LPCSTR lpProcName);
static FARPROC WINAPI _new_kernel32__GetProcAddress(HMODULE hModule, LPCSTR lpProcName);
static XYO::Win::Inject::Hook::HookProc _hook_kernel32__GetProcAddress;
#define _original_kernel32__GetProcAddress ((_ptr_kernel32__GetProcAddress)(_hook_kernel32__GetProcAddress.originalProc))
