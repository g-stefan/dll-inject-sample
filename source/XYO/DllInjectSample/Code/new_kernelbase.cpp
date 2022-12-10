typedef BOOL(WINAPI *_ptr_kernelbase__CreateProcessA)(LPCTSTR lpApplicationName, LPTSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCTSTR lpCurrentDirectory, LPSTARTUPINFO lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation);
static BOOL WINAPI _new_kernelbase__CreateProcessA(LPCTSTR lpApplicationName, LPTSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCTSTR lpCurrentDirectory, LPSTARTUPINFO lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation);
static XYO::Win::Inject::Hook::HookProc _hook_kernelbase__CreateProcessA;
#define _original_kernelbase__CreateProcessA ((_ptr_kernelbase__CreateProcessA)(_hook_kernelbase__CreateProcessA.originalProc))
typedef BOOL(WINAPI *_ptr_kernelbase__CreateProcessW)(LPCTSTR lpApplicationName, LPTSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCTSTR lpCurrentDirectory, LPSTARTUPINFO lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation);
static BOOL WINAPI _new_kernelbase__CreateProcessW(LPCTSTR lpApplicationName, LPTSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCTSTR lpCurrentDirectory, LPSTARTUPINFO lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation);
static XYO::Win::Inject::Hook::HookProc _hook_kernelbase__CreateProcessW;
#define _original_kernelbase__CreateProcessW ((_ptr_kernelbase__CreateProcessW)(_hook_kernelbase__CreateProcessW.originalProc))
typedef HMODULE(WINAPI *_ptr_kernelbase__LoadLibraryA)(const char *lpFileName);
static HMODULE WINAPI _new_kernelbase__LoadLibraryA(const char *lpFileName);
static XYO::Win::Inject::Hook::HookProc _hook_kernelbase__LoadLibraryA;
#define _original_kernelbase__LoadLibraryA ((_ptr_kernelbase__LoadLibraryA)(_hook_kernelbase__LoadLibraryA.originalProc))
typedef HINSTANCE(WINAPI *_ptr_kernelbase__LoadLibraryExA)(const char *lpLibFileName, HANDLE hFile, DWORD dwFlags);
static HINSTANCE WINAPI _new_kernelbase__LoadLibraryExA(const char *lpLibFileName, HANDLE hFile, DWORD dwFlags);
static XYO::Win::Inject::Hook::HookProc _hook_kernelbase__LoadLibraryExA;
#define _original_kernelbase__LoadLibraryExA ((_ptr_kernelbase__LoadLibraryExA)(_hook_kernelbase__LoadLibraryExA.originalProc))
typedef HINSTANCE(WINAPI *_ptr_kernelbase__LoadLibraryExW)(const wchar_t *lpLibFileName, HANDLE hFile, DWORD dwFlags);
static HINSTANCE WINAPI _new_kernelbase__LoadLibraryExW(const wchar_t *lpLibFileName, HANDLE hFile, DWORD dwFlags);
static XYO::Win::Inject::Hook::HookProc _hook_kernelbase__LoadLibraryExW;
#define _original_kernelbase__LoadLibraryExW ((_ptr_kernelbase__LoadLibraryExW)(_hook_kernelbase__LoadLibraryExW.originalProc))
typedef HMODULE(WINAPI *_ptr_kernelbase__LoadLibraryW)(const wchar_t *lpFileName);
static HMODULE WINAPI _new_kernelbase__LoadLibraryW(const wchar_t *lpFileName);
static XYO::Win::Inject::Hook::HookProc _hook_kernelbase__LoadLibraryW;
#define _original_kernelbase__LoadLibraryW ((_ptr_kernelbase__LoadLibraryW)(_hook_kernelbase__LoadLibraryW.originalProc))
typedef FARPROC(WINAPI *_ptr_kernelbase__GetProcAddress)(HMODULE hModule, LPCSTR lpProcName);
static FARPROC WINAPI _new_kernelbase__GetProcAddress(HMODULE hModule, LPCSTR lpProcName);
static XYO::Win::Inject::Hook::HookProc _hook_kernelbase__GetProcAddress;
#define _original_kernelbase__GetProcAddress ((_ptr_kernelbase__GetProcAddress)(_hook_kernelbase__GetProcAddress.originalProc))
