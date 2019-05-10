typedef BOOL (WINAPI *_ptr_advapi32__CreateProcessAsUserA)(HANDLE hToken, LPCTSTR lpApplicationName, LPTSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCTSTR lpCurrentDirectory, LPSTARTUPINFO lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation);
static BOOL WINAPI _new_advapi32__CreateProcessAsUserA(HANDLE hToken, LPCTSTR lpApplicationName, LPTSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCTSTR lpCurrentDirectory, LPSTARTUPINFO lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation);
static XYO::Win::Inject::Hook::HookProc _hook_advapi32__CreateProcessAsUserA;
#define _original_advapi32__CreateProcessAsUserA ((_ptr_advapi32__CreateProcessAsUserA)(_hook_advapi32__CreateProcessAsUserA.originalProc))
typedef BOOL (WINAPI *_ptr_advapi32__CreateProcessAsUserW)(HANDLE hToken, LPCTSTR lpApplicationName, LPTSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCTSTR lpCurrentDirectory, LPSTARTUPINFO lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation);
static BOOL WINAPI _new_advapi32__CreateProcessAsUserW(HANDLE hToken, LPCTSTR lpApplicationName, LPTSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCTSTR lpCurrentDirectory, LPSTARTUPINFO lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation);
static XYO::Win::Inject::Hook::HookProc _hook_advapi32__CreateProcessAsUserW;
#define _original_advapi32__CreateProcessAsUserW ((_ptr_advapi32__CreateProcessAsUserW)(_hook_advapi32__CreateProcessAsUserW.originalProc))
