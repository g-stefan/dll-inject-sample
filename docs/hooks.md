# Hook catalogue

Every hooked function, grouped by the module whose Import Address Table entry is
redirected to it. The hook bodies are in
`source/XYO/DllInjectSample/Code/new_<module>__<Function>.cpp`; the list of what
is hooked is driven by [`fabricare/hooks.cmd`](../fabricare/hooks.cmd) (see
[extending.md](extending.md)).

All hooks call the real function through the saved `originalProc` and, where
they do extra work, save and restore `GetLastError` so the target observes the
exact error state the real API produced.

## Loader — keep the hooks spreading

Hooked in `kernel32`, `kernelbase`, and the API-set
`api-ms-win-core-libraryloader-l1-2-0` (newer binaries import the loader through
this alias).

| Function | What the hook does |
|----------|--------------------|
| `LoadLibraryA` / `LoadLibraryW` | call the real loader, then `thisHookInstance(result)` to rewrite the newly loaded module's IAT |
| `LoadLibraryExA` / `LoadLibraryExW` | same, but skip modules loaded with `DONT_RESOLVE_DLL_REFERENCES` or `LOAD_LIBRARY_AS_DATAFILE` (they call nothing) |
| `GetProcAddress` | resolve for real, then return the *hooked* `LoadLibraryW` / `LoadLibraryExW` when those are requested, so dynamic resolution also yields the instrumented loader |

## Process creation — propagate into children

Hooked in `kernel32`, `kernelbase` (`CreateProcess*`, `LoadModule`),
`advapi32` (`CreateProcessAsUser*`), and `api-ms-win-core-processthreads-l1-1-2`
(`CreateProcessW`). Each forwards to `xyo-win-inject`'s `Process::createProcess*`
with this DLL's own path, so the child is created with the sample injected, then
resumed unless the caller asked for a suspended process.

| Function | Notes |
|----------|-------|
| `CreateProcessA` / `CreateProcessW` | the common case; child launched with the DLL injected |
| `CreateProcessAsUserA` / `CreateProcessAsUserW` | same, under a supplied token |
| `LoadModule` | legacy entry; its `LOADPARMS32` block is translated into a `STARTUPINFO` + command line and run through `createProcessA` |

## Network — observe traffic (taps are stubs)

Hooked in `ws2_32` (Winsock 2) and `wsock32` (the Winsock 1.1 shim). The capture
points `recvHookProcess` / `sendHookProcess` receive each buffer and length; the
recording code is commented out, ready for you to fill in.

| Function | What the hook captures |
|----------|------------------------|
| `recv` | received bytes on success (`ws2_32` and `wsock32`) |
| `send` | sent bytes on success (`ws2_32` and `wsock32`) |
| `connect` / `bind` | pass-through (call the original; a place to inspect addresses) |
| `WSAConnect` | pass-through |
| `WSASend` / `WSARecv` | remember the overlapped request (buffers, count, overlapped pointer) in per-thread state |
| `WSAGetOverlappedResult` | on completion, match the overlapped pointer to the remembered `WSASend`/`WSARecv` and walk the `WSABUF` scatter/gather list, handing each chunk to the tap |

`wininet` (WinINet, the higher-level HTTP/FTP client):

| Function | What the hook does |
|----------|--------------------|
| `InternetConnectA` / `InternetConnectW` | pass-through (a place to inspect server/port/credentials) |
| `InternetReadFile` | capture the bytes read on success |

## Why these modules are on the skip list

`processModule` is told to skip `NTDLL`, `KERNEL32`, `KERNELBASE`, `ICMP`,
`WININET`, `WS2_32`, `WSOCK32`. Those modules *own* the real functions; if their
own import tables were rewritten, a hook that calls `originalProc` could be
routed back into itself. Skipping them means the hooks apply to every *consumer*
of these APIs while the implementations stay intact.
