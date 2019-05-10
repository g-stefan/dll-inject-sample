typedef HINSTANCE (WINAPI *_ptr_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExA)(const char *lpLibFileName, HANDLE hFile, DWORD dwFlags);
static HINSTANCE WINAPI _new_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExA(const char *lpLibFileName, HANDLE hFile, DWORD dwFlags);
static XYO::Win::Inject::Hook::HookProc _hook_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExA;
#define _original_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExA ((_ptr_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExA)(_hook_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExA.originalProc))
typedef HINSTANCE (WINAPI *_ptr_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExW)(const wchar_t *lpLibFileName, HANDLE hFile, DWORD dwFlags);
static HINSTANCE WINAPI _new_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExW(const wchar_t *lpLibFileName, HANDLE hFile, DWORD dwFlags);
static XYO::Win::Inject::Hook::HookProc _hook_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExW;
#define _original_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExW ((_ptr_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExW)(_hook_api_ms_win_core_libraryloader_l1_2_0__LoadLibraryExW.originalProc))
typedef FARPROC (WINAPI *_ptr_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress)(HMODULE hModule, LPCSTR lpProcName);
static FARPROC WINAPI _new_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress(HMODULE hModule, LPCSTR lpProcName);
static XYO::Win::Inject::Hook::HookProc _hook_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress;
#define _original_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress ((_ptr_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress)(_hook_api_ms_win_core_libraryloader_l1_2_0__GetProcAddress.originalProc))
