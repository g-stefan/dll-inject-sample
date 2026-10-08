# Dll inject sample — Documentation

`dll-inject-sample` is the **payload DLL** of the XYO DLL-injection toolchain.
It is a small Windows DLL that, once loaded into a target process, rewrites that
process's **Import Address Table (IAT)** so that a curated set of Win32 API
calls (the module loader, process creation, and network I/O) are redirected
through its own functions. From there it can observe those calls and, for
process-creation and library-loading APIs, keep itself attached as the program
grows — loading into newly loaded modules and propagating into child processes.

It is a *sample*: the hook functions are complete and correct, but the points
where you would record or alter data (the `recvHookProcess` / `sendHookProcess`
taps) are left as empty stubs with the logging code commented out. The value of
the project is the **wiring** — a worked example of how to stand up a broad,
self-propagating IAT hook using [`xyo-win-inject`](https://github.com/g-stefan/xyo-win-inject).

```
dll-inject            launcher .exe  (injects this DLL into a target)
dll-inject-sample     <-- this payload DLL
xyo-win-inject        inject + IAT-hook engine (Process::*, Hook::*)
xyo-win               windows.h, Win32 helpers, StringCore
xyo-system / xyo-encoding / ... / xyo-platform
```

## Purpose and intended use

DLL injection with IAT hooking is the standard Windows technique behind
debuggers, profilers, API monitors, test harnesses, compatibility shims,
telemetry and instrumentation layers. This project demonstrates a *monitoring*
payload: inject it into a program you own or are authorized to test, attach a
debug-output viewer, and watch which libraries it loads, which child processes
it spawns, and (where you enable the taps) the bytes it sends and receives.

The DLL grants **no new privilege**. It needs exactly the rights Windows already
requires to load a DLL into the target, and it only works when the target and
the DLL are the **same bitness**. Use it only on processes you control or are
permitted to instrument.

> **It propagates.** Because it hooks `CreateProcess*` / `CreateProcessAsUser*` /
> `LoadModule`, any child process the target starts is created with this same DLL
> injected, and because it hooks `LoadLibrary*` it re-hooks modules the target
> loads later. That reach is the point of the sample — but it means injecting it
> into, say, a shell will fan the hook out across everything that shell launches.
> Keep that in mind when choosing a target.

## What it hooks

| Module | Functions | Why |
|--------|-----------|-----|
| `kernel32`, `kernelbase` | `CreateProcessA/W`, `CreateProcessAsUser*` (advapi32), `LoadModule` | re-create children with the DLL injected (self-propagation) |
| `kernel32`, `kernelbase`, `api-ms-win-core-libraryloader-l1-2-0` | `LoadLibraryA/W`, `LoadLibraryExA/W` | hook the IAT of modules loaded after startup |
| `kernel32`, `kernelbase`, `api-ms-win-core-libraryloader-l1-2-0` | `GetProcAddress` | return the hooked loader for dynamically resolved functions |
| `api-ms-win-core-processthreads-l1-1-2` | `CreateProcessW` | the API-set alias used by newer binaries |
| `ws2_32`, `wsock32` | `connect`, `bind`, `send`, `recv`, `WSAConnect`, `WSASend`, `WSARecv`, `WSAGetOverlappedResult` | observe socket traffic (taps are stubs) |
| `wininet` | `InternetConnectA/W`, `InternetReadFile` | observe WinINet traffic (taps are stubs) |

See [hooks.md](hooks.md) for the per-function catalogue.

## Contents

| Document | What it covers |
|----------|----------------|
| [Getting started](getting-started.md) | Build the DLL, inject it with `dll-inject`, watch it work, bitness and safety |
| [How it works](how-it-works.md) | `DllMain`, the IAT rewrite, self-propagation, per-thread state, `GetProcAddress` interception |
| [Hook catalogue](hooks.md) | Every hooked API, grouped by module, and what its hook does |
| [Extending & regenerating](extending.md) | `fabricare/hooks.cmd`, `xyo-generate-hook`, adding or changing a hook |

## Source map

```
source/XYO/DllInjectSample/
    Library.cpp              DllMain, hook list, GetProcAddress interceptor, propagation glue
    Library.hpp              umbrella header
    Dependency.hpp           xyo-win-inject include + XYO_DLLINJECTSAMPLE_EXPORT macros
    Copyright / License / Version    DLL metadata (.cpp/.hpp/.rh)
    Library.rc / Library.rh  version resource for the DLL
    Code/                    the hook functions, generated-then-filled (see extending.md)
        new_<module>.cpp                   typedefs + HookProc objects per function
        new_<module>__<Fn>.cpp             the hook body for one function (hand-written)
        new_<module>___proc.cpp            #includes every __<Fn>.cpp for that module
        new_<module>___hookProc.cpp        the module's entries for the global hook list
        new_<module>___setOriginalFunction.cpp   resolves originals at startup
fabricare.json               build manifest (make: dll)
fabricare/hooks.cmd          regenerates the Code/ skeletons via xyo-generate-hook
test/                        structural checks of the built DLL (see getting-started.md)
```

## AI assistant skill

A Claude Code skill summarizing how to use and extend this project lives in
[`.claude/skills/dll-inject-sample/`](../.claude/skills/dll-inject-sample/SKILL.md).
It is picked up automatically inside this repository; copy the folder to
`~/.claude/skills/` to have it available elsewhere.

## License

Copyright (c) 2014-2026 Grigore Stefan. Licensed under the [MIT](../LICENSE)
license.
