XYO::Win::Inject::Hook::setOriginalFunction(_hook_kernel32__CreateProcessA, "kernel32", "CreateProcessA", (FARPROC)_new_kernel32__CreateProcessA);
XYO::Win::Inject::Hook::setOriginalFunction(_hook_kernel32__CreateProcessW, "kernel32", "CreateProcessW", (FARPROC)_new_kernel32__CreateProcessW);
XYO::Win::Inject::Hook::setOriginalFunction(_hook_kernel32__LoadLibraryA, "kernel32", "LoadLibraryA", (FARPROC)_new_kernel32__LoadLibraryA);
XYO::Win::Inject::Hook::setOriginalFunction(_hook_kernel32__LoadLibraryExA, "kernel32", "LoadLibraryExA", (FARPROC)_new_kernel32__LoadLibraryExA);
XYO::Win::Inject::Hook::setOriginalFunction(_hook_kernel32__LoadLibraryExW, "kernel32", "LoadLibraryExW", (FARPROC)_new_kernel32__LoadLibraryExW);
XYO::Win::Inject::Hook::setOriginalFunction(_hook_kernel32__LoadLibraryW, "kernel32", "LoadLibraryW", (FARPROC)_new_kernel32__LoadLibraryW);
XYO::Win::Inject::Hook::setOriginalFunction(_hook_kernel32__LoadModule, "kernel32", "LoadModule", (FARPROC)_new_kernel32__LoadModule);
XYO::Win::Inject::Hook::setOriginalFunction(_hook_kernel32__GetProcAddress, "kernel32", "GetProcAddress", (FARPROC)_new_kernel32__GetProcAddress);
