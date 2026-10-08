# How it works

All of the sample's behaviour is driven from
[`Library.cpp`](../source/XYO/DllInjectSample/Library.cpp); the per-function
hook bodies live under `Code/` and are `#include`d into it. This page walks the
flow from load to steady state.

## 1. `DllMain` on attach

When the DLL is loaded into the target (by the injected `LoadLibraryA`), the
`DLL_PROCESS_ATTACH` case runs once, guarded by an `isAttached` flag:

1. Record the target's own executable path (`GetModuleFileName(NULL, …)`) and
   this DLL's path (`thisModuleFileName`). The DLL path is reused later to
   inject child processes.
2. Allocate a **thread-local storage** slot (`TlsAlloc`) for per-thread hook
   state. If that fails the DLL refuses to load (`return FALSE`).
3. `setOriginalFunction()` — for every function in the hook list, resolve the
   *real* address in its owning module and remember it, plus its name and
   ordinal. This is `xyo-win-inject`'s `Hook::setOriginalFunction`.
4. `thisHookInstance(GetModuleHandle(NULL))` — rewrite the import tables of the
   main module and, recursively, everything it imports.

`DLL_THREAD_ATTACH` / `DLL_THREAD_DETACH` allocate and free the per-thread state
block; `DLL_PROCESS_DETACH` releases the TLS slot.

## 2. The hook list

Each hooked function contributes a `HookProc` (declared in its
`new_<module>.cpp`) and a pointer to that `HookProc` in the global,
`nullptr`-terminated `hookList[]`. A `HookProc` ties together:

- `originalProc` — the real function, filled in by `setOriginalFunction`;
- `newProc` — the sample's replacement;
- `hModule`, `procName`, `procOrdinal` — the owning module and identity.

Calling the original from inside a hook goes through the `_original_<...>` macro,
which is just `originalProc` cast back to the correct function-pointer type.

## 3. Rewriting the IAT (`thisHookInstance` → `processModule`)

`thisHookInstance` calls `Hook::processModule`, which:

- walks a module's import descriptors, and for every imported address that
  matches a `HookProc::originalProc`, overwrites the IAT slot with `newProc`
  (via `VirtualProtect` to make the slot writable);
- recurses into each imported module, so indirect callers are covered too;
- keeps a **processed list** (`loadedModules[]`, up to 16380 entries) to avoid
  walking a module twice and to break import cycles;
- honours a **skip list** — `NTDLL`, `KERNEL32`, `KERNELBASE`, `ICMP`,
  `WININET`, `WS2_32`, `WSOCK32` — so the modules that *own* the real functions
  are not themselves rewritten (which would send a hook straight back into
  itself).

Because the IAT stores the address the caller jumps to, rewriting it is
transparent: the target calls `recv`, the loader-resolved slot now points at
`_new_ws2_32__recv`, which does its work and then calls the saved `originalProc`.

## 4. Staying attached as the target grows

Two families of hooks keep the coverage from going stale:

**Loader hooks** — `LoadLibraryA/W`, `LoadLibraryExA/W`. After calling the real
loader they pass the freshly loaded module to `thisHookInstance`, so its import
table is rewritten immediately. `LoadLibraryEx*` skips this when the module was
loaded with `DONT_RESOLVE_DLL_REFERENCES` or `LOAD_LIBRARY_AS_DATAFILE` (such a
module will not call anything, so there is nothing to hook). Each hook preserves
`GetLastError` around its extra work.

**`GetProcAddress`** — `hook_GetProcAddress` calls the real `GetProcAddress`,
then checks the result against the hook list. For `LoadLibraryW` /
`LoadLibraryExW` it returns the *hooked* address instead of the real one, so
code that resolves the loader dynamically still gets the instrumented version.
(The matching report lines use `OutputDebugStringA`.)

## 5. Propagating into child processes

The process-creation hooks — `CreateProcessA/W`, `CreateProcessAsUserA/W`,
`LoadModule` — do **not** call the real API directly. They forward to
`xyo-win-inject`'s `Process::createProcess*`, passing `thisModuleFileName` (this
DLL's own path) as the DLL to inject. That helper:

- creates the child **suspended** (it ORs in `CREATE_SUSPENDED`);
- injects the DLL before the child runs its first instruction;
- resumes the child **only if the caller did not ask for a suspended process** —
  the hook recomputes the caller's original `CREATE_SUSPENDED` intent and
  resumes once when appropriate, so a caller that expected a suspended process
  still gets one.

The result is self-propagation: every process the target launches starts with
`dll-inject-sample.dll` already inside it.

`LoadModule` (the legacy 16-bit-style entry) is rebuilt on top of
`createProcessA`, translating its `LOADPARMS32` block into a `STARTUPINFO` /
command line.

## 6. Per-thread state and the network taps

Socket and WinINet reads/writes can span several calls and overlapped
completions, so the sample keeps a `HookProcess` block **per thread** in the TLS
slot (`getHookProcess()` lazily creates one). It is used to correlate
overlapped `WSASend`/`WSARecv` with their later `WSAGetOverlappedResult`
completion, walking the scatter/gather `WSABUF` list to hand each contiguous
chunk to the tap.

The taps themselves — `recvHookProcess` / `sendHookProcess` — are **stubs**: they
receive the buffer and length but the recording code (per-thread capture files)
is commented out. This is where you add logging or inspection. Every network and
loader hook also preserves `GetLastError` around its own work so the target sees
the exact error state the real API produced.

## 7. A note on unloading

The sample is designed to live for the lifetime of the process it is injected
into. On `DLL_PROCESS_DETACH` it frees its TLS slot but does **not** restore the
import tables it rewrote, so forcibly `FreeLibrary`-ing it out of a running
process would leave dangling IAT slots. Inject it and let it run; do not unload
it by hand.
