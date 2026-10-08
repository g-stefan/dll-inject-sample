# Extending & regenerating hooks

The files under `source/XYO/DllInjectSample/Code/` are **generated skeletons
that are then filled in by hand**. The generator is `xyo-generate-hook.exe`
(from the fabricare SDK `bin`), driven by
[`fabricare/hooks.cmd`](../fabricare/hooks.cmd).

## What the generator produces

For a module `M` it (re)creates four aggregation files:

```
new_M.cpp                      typedef + HookProc object + _original_M__Fn macro, per function
new_M___proc.cpp               #includes every new_M__Fn.cpp
new_M___hookProc.cpp           &_hook_M__Fn,  entries for the global hook list
new_M___setOriginalFunction.cpp   Hook::setOriginalFunction(...) calls run at startup
```

and, for each function, a per-function body file:

```
new_M__Fn.cpp                  the hook itself
```

A freshly generated `new_M__Fn.cpp` is a **pass-through skeleton**: it declares
`retV`, calls `_original_M__Fn(...)`, and returns. The real behaviour — calling
`thisHookInstance`, forwarding to `createProcess*`, capturing buffers,
preserving `GetLastError` — is written in afterwards. `hooks.cmd` therefore
`del`etes and regenerates only the four aggregation files per module; it does
**not** overwrite the per-function bodies you have edited.

> If you run the generator for a function that does not yet have a body file, it
> writes the skeleton; if the body file already exists it is left as-is. Never
> blanket-delete the `new_M__Fn.cpp` files — that discards the hand-written hooks.

## `hooks.cmd`

```bat
Set GEN=xyo-generate-hook.exe
pushd "source/XYO/DllInjectSample/Code"

rem per module: delete the four aggregation files, then one %GEN% line per function
del /F /Q new_kernel32.cpp
del /F /Q new_kernel32___setOriginalFunction.cpp
del /F /Q new_kernel32___hookProc.cpp
del /F /Q new_kernel32___proc.cpp
%GEN% kernel32 WINAPI HMODULE LoadLibraryW "const wchar_t *lpFileName"
...
popd
```

Each `%GEN%` line is:

```
%GEN% <module> <callconv> <returnType> <FunctionName> "<comma-separated parameters>"
```

Run it from the repository root (it needs `xyo-generate-hook.exe` on `PATH`,
which the fabricare SDK `bin` provides):

```bash
cmd /c fabricare\hooks.cmd
```

## Adding a hook for a new function

1. Add a `del /F /Q` block (if the module is new) and a `%GEN%` line for the
   function in `fabricare/hooks.cmd`, then run it to refresh the aggregation
   files and drop a skeleton body.
2. Fill in `new_<module>__<Fn>.cpp` with the real hook: call `_original_...`,
   do your work, preserve `GetLastError` if you touch it, and return.
3. If the function is a loader or process-creation entry, call
   `thisHookInstance(...)` / `Process::createProcess*(...)` as the existing
   hooks do.
4. Make sure `Library.cpp` `#include`s the module's aggregation files in all
   four of its sections (`new_<module>.cpp`, `___proc`, `___hookProc`,
   `___setOriginalFunction`) and, if the module owns the functions you hook, add
   it to `dllHookSkip[]`.
5. `fabricare make` and, for a quick artifact sanity check, `fabricare test`.

## Build settings

See [`fabricare.json`](../fabricare.json): the project builds as a `dll`,
depends on `xyo-platform.static` and `xyo-win-inject.static`, and links the
static CRT, so the resulting DLL is self-contained and safe to inject into a
process that has none of the XYO runtime DLLs on its search path. Version numbers
come from [`version.json`](../version.json) and are stamped into the DLL through
`Library.rc` / the `Version` sources.
