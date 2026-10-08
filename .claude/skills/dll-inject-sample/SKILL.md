---
name: dll-inject-sample
description: >-
  How to understand, build, use and extend dll-inject-sample, the sample payload
  DLL of the XYO DLL-injection toolchain (built on xyo-win-inject, injected by
  the dll-inject launcher). Once loaded into a target Windows process it rewrites
  that process's Import Address Table (IAT) to redirect a curated set of Win32
  APIs through its own hooks: the module loader (LoadLibraryA/W, LoadLibraryExA/W,
  GetProcAddress), process creation (CreateProcessA/W, CreateProcessAsUserA/W,
  LoadModule) which re-inject the DLL into child processes so it self-propagates,
  and network I/O (ws2_32 and wsock32 connect/bind/send/recv/WSAConnect/WSASend/
  WSARecv/WSAGetOverlappedResult, wininet InternetConnectA/W/InternetReadFile)
  whose capture taps recvHookProcess/sendHookProcess are left as stubs. Covers
  DllMain, the hook list, thisHookInstance/processModule IAT rewrite, the skip
  list, per-thread TLS HookProcess state, the GetProcAddress interceptor, and
  regenerating the Code/ skeletons with fabricare/hooks.cmd and
  xyo-generate-hook. Use when working inside the dll-inject-sample repository,
  when building or injecting dll-inject-sample.dll, when adding or changing a
  hooked API, or when reviewing code under source/XYO/DllInjectSample.
---

# dll-inject-sample

The **payload DLL** of the XYO DLL-injection toolchain. Inject it into a Windows
process (with the [`dll-inject`](https://github.com/g-stefan/dll-inject)
launcher, or any launcher built on
[`xyo-win-inject`](https://github.com/g-stefan/xyo-win-inject)) and it rewrites
that process's Import Address Table so selected Win32 calls run through its own
hooks — observing them and keeping itself attached as the program loads more
modules and spawns child processes.

It is a **sample**: the hook wiring is complete and correct, but the data taps
(`recvHookProcess` / `sendHookProcess`) are empty stubs with the recording code
commented out. The point is the worked example of standing up a broad,
self-propagating IAT hook. Windows only (MSVC / MinGW, `win32` / `win64`); no
Linux build.

Full docs: `docs/` in this repo (README, getting-started, how-it-works, hooks,
extending). The engine it uses is documented by the `xyo-win-inject` skill; its
rules and the `xyo-system` / `xyo-platform` skills apply.

## Scope / safety

Legitimate instrumentation (debuggers, profilers, API monitors, test harnesses,
compat shims) for processes you own or are authorized to modify. It grants no
new privilege — it needs the rights Windows already requires to load a DLL into
the target. Two things to keep in mind:

- **Bitness must match**: a 64-bit target loads only a 64-bit DLL, 32-bit only
  32-bit. Wrong bitness ⇒ `LoadLibrary` fails in the target.
- **It propagates.** Hooking `CreateProcess*` / `CreateProcessAsUser*` /
  `LoadModule` means every child the target starts is created with this DLL
  injected; hooking `LoadLibrary*` re-hooks modules loaded later. Injecting into
  a shell fans the hook out across everything it launches — choose the target
  deliberately.

## How it is wired (source/XYO/DllInjectSample)

Everything is driven from `Library.cpp`, which `#include`s the hook bodies under
`Code/`.

- **`DllMain` / `DLL_PROCESS_ATTACH`** (once, guarded by `isAttached`): record
  the target path and this DLL's path (`thisModuleFileName`, reused to inject
  children); `TlsAlloc` a per-thread state slot (fail ⇒ `return FALSE`);
  `setOriginalFunction()` to resolve every real function; then
  `thisHookInstance(GetModuleHandle(NULL))` to rewrite the import graph.
  `DLL_THREAD_ATTACH/DETACH` manage per-thread state; `DLL_PROCESS_DETACH` frees
  the TLS slot (it does **not** restore the IAT — do not `FreeLibrary` it out of
  a live process).
- **`hookList[]`** — `nullptr`-terminated array of `XYO::Win::Inject::Hook::HookProc*`.
  Each hooked function has a `HookProc` (`originalProc` filled by
  `setOriginalFunction`, `newProc` = the sample's replacement). Hooks call the
  original via the `_original_<module>__<Fn>` macro.
- **`thisHookInstance` → `Hook::processModule`** rewrites a module's IAT and
  recurses into its imports, using `loadedModules[]` (≤16380) as the processed
  list and `dllHookSkip[]` (`NTDLL`, `KERNEL32`, `KERNELBASE`, `ICMP`,
  `WININET`, `WS2_32`, `WSOCK32`) as the skip list so the owning modules are not
  rewritten into themselves.
- **Loader hooks** (`kernel32`, `kernelbase`, `api-ms-win-core-libraryloader-l1-2-0`):
  `LoadLibrary*` call the real loader then `thisHookInstance(result)`;
  `LoadLibraryEx*` skip `DONT_RESOLVE_DLL_REFERENCES` / `LOAD_LIBRARY_AS_DATAFILE`.
  `hook_GetProcAddress` returns the hooked `LoadLibraryW`/`LoadLibraryExW` for
  dynamic resolvers.
- **Process-creation hooks** (`kernel32`, `kernelbase`, `advapi32`,
  `api-ms-win-core-processthreads-l1-1-2`): forward to
  `Process::createProcess*(..., thisModuleFileName)`, which creates the child
  suspended, injects, and resumes unless the caller asked for `CREATE_SUSPENDED`.
  `LoadModule` translates its `LOADPARMS32` into a `STARTUPINFO` + command line.
- **Network hooks** (`ws2_32`, `wsock32`, `wininet`): capture `recv`/`send`
  buffers; keep per-thread `HookProcess` state to correlate overlapped
  `WSASend`/`WSARecv` with `WSAGetOverlappedResult` and walk the `WSABUF` list.
  Every hook preserves `GetLastError` around its extra work. The taps are stubs.

## The Code/ files are generated-then-filled

Per module `M`, `xyo-generate-hook.exe` (SDK `bin`), driven by
`fabricare/hooks.cmd`, regenerates four aggregation files — `new_M.cpp`
(typedefs + `HookProc`s + `_original_` macros), `new_M___proc.cpp` (includes the
bodies), `new_M___hookProc.cpp` (hook-list entries), `new_M___setOriginalFunction.cpp`
— and a **skeleton** `new_M__Fn.cpp` per function. The per-function bodies are
then **hand-written** (the real `thisHookInstance` / `createProcess*` / capture
logic). So:

- Re-run with `cmd /c fabricare\hooks.cmd` to refresh aggregation files; it does
  **not** overwrite existing body files.
- Never blanket-delete the `new_M__Fn.cpp` bodies — that discards the hooks.
- A `%GEN%` line is `%GEN% <module> <callconv> <returnType> <Fn> "<params>"`.
- To add a hook: add the `del`/`%GEN%` lines, fill in the body, make sure
  `Library.cpp` includes the module in all four sections, add the module to
  `dllHookSkip[]` if it owns the hooked functions.

> `fabricare/hooks.cmd` begins `Set GEN=xyo-generate-hook.exe` on its **own
> line**, below the `rem` license-identifier comment header. Keep that newline —
> if `Set GEN=...` is joined onto the `rem` line it becomes part of the comment,
> `%GEN%` stays empty, and every generator line silently fails.

## Build (fabricare)

```bash
fabricare make      # output/bin/dll-inject-sample.dll (make: dll, static CRT)
fabricare test      # build + run test.01 (PE/DLL/bitness/entry) and test.02 (version resource); make first
fabricare install   # copy into ~/.fabricare/<platform>
fabricare clean
```

On this machine use platform `win64-msvc-2026` and clear
`NoDefaultCurrentDirectoryInExePath` for the fabricare child process (see the
`fabricare` skill). Dependencies: `xyo-platform.static`, `xyo-win-inject.static`
(install them first). Source files are **CRLF** — normalize new/edited files and
check `git ls-files --eol` shows `w/crlf` before committing; do not use
`sed -i` (it rewrites the whole file to LF) — use a binary-mode edit.

## Tests

`test/test.01.cpp` and `test/test.02.cpp` are structural checks of the built
`dll-inject-sample.dll` (it is a PE DLL of the right bitness with an entry point;
it carries a version resource matching `version.json`). They run in-process and
inject nothing, so they are safe anywhere. Run `fabricare make` before
`fabricare test`. Add more as `test/test.NN.cpp` plus a `category: "test"`
project in `fabricare.json`.
