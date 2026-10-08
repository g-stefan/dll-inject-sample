# Getting started

## 1. Build

The project is built with [fabricare](https://github.com/g-stefan/fabricare),
the build tool shared by all XYO C++ projects. Its dependencies —
`xyo-platform` and `xyo-win-inject` (which transitively pulls `xyo-win`,
`xyo-system`, `xyo-encoding`, …) — must be installed into the SDK first. From
the repository root:

```bash
fabricare make       # build the DLL into output/bin
fabricare test       # build and run the structural tests (run make first)
fabricare install    # copy output/{bin,include,lib} to ~/.fabricare/<platform>
fabricare clean      # remove output/ and temp/
```

The result is a single DLL, `dll-inject-sample.dll`, in `output/bin`. It links
the static CRT and the static variants of its dependencies
(`xyo-platform.static`, `xyo-win-inject.static`), so the DLL is self-contained
and can be injected into a process that does not have the XYO runtime DLLs on
its search path.

This is a **Windows-only** project (MSVC / MinGW, `win32` / `win64`). There is
no Linux build.

## 2. Bitness and privileges (read before you inject)

- **Bitness must match.** A 64-bit process can only load a 64-bit DLL and a
  32-bit process only a 32-bit DLL. Build `dll-inject-sample.dll` for the same
  architecture as the target. The wrong bitness makes `LoadLibrary` inside the
  target fail (and `dll-inject` will terminate the process it created).
- **The DLL path must be reachable by the target.** Injection calls
  `LoadLibraryA` *inside the target process* with the DLL's full path, so use a
  full ASCII path.
- **Rights.** Launching a process already grants the rights injection needs. To
  inject into a process you did not create you need VM-write / create-thread /
  thread-context access on it, which may require a matching integrity level or
  `SeDebugPrivilege`.
- **Only your own / authorized targets**, and remember it **propagates into
  child processes** (see [how-it-works.md](how-it-works.md)).

## 3. Inject it with `dll-inject`

The companion launcher [`dll-inject`](https://github.com/g-stefan/dll-inject)
starts a program with a DLL attached before its first instruction runs:

```bash
dll-inject "C:\path\to\target.exe --its-args" "C:\path\to\dll-inject-sample.dll"
```

Equivalently, from your own launcher built on `xyo-win-inject`:

```cpp
#include <XYO/WinInject.hpp>
using namespace XYO::Win::Inject;

int main() {
	char cmdLine[] = "C:\\Windows\\System32\\notepad.exe";
	if (!Process::injectDll(cmdLine, "C:\\build\\dll-inject-sample.dll")) {
		printf("injection failed: %lu\n", GetLastError());
		return 1;
	};
	return 0;
}
```

`cmdLine` is passed to `CreateProcessA`, which may modify the buffer in place —
pass a writable `char` array, not a string literal.

## 4. Watch it work

The sample reports through `OutputDebugString`, so run a debug-output viewer
(Sysinternals **DebugView**, or your debugger's Output window) with the target
elevated to match, then inject. On attach you will see lines such as:

```
--- hook ---
C:\Windows\System32\notepad.exe       (the target process path)
C:\build\dll-inject-sample.dll        (this DLL's path)
--- imports ---
#hook: C:\Windows\System32\notepad.exe
```

and, as the target loads more libraries, further `#hook:` lines for each module
whose import table was rewritten.

To make the network and loader hooks *do* something, uncomment the taps — the
`OutputDebugStringA(...)` lines at the top of each hook body in
`source/XYO/DllInjectSample/Code/new_*.cpp`, and the file-logging code in
`recvHookProcess` / `sendHookProcess` / `newHookProcess` in `Library.cpp` — then
rebuild. The stubs already receive the captured buffers; you only need to decide
what to record.

## 5. Run the tests

```bash
fabricare make
fabricare test
```

The tests are structural checks of the **built artifact** and run entirely
in-process without injecting anything, so they are safe to run anywhere:

- `test.01` confirms `output/bin/dll-inject-sample.dll` is a well-formed PE
  **DLL** built for this toolchain's architecture (the bitness invariant that
  injection depends on) and that it has an entry point (`DllMain`).
- `test.02` confirms the DLL carries a valid version resource whose numbers
  match `version.json`.

Run `fabricare make` first: `fabricare test` only builds and runs the test
executables, it does not (re)build the DLL they inspect. See [`test/`](../test).

## 6. Building without fabricare

You can compile the sources directly with MSVC; provide the include/lib paths
for `xyo-win-inject` and its dependencies, compile `source/XYO/DllInjectSample/*.cpp`
(`Library.cpp` `#include`s everything under `Code/`), add `Library.rc`, and link
as a DLL. See [`Dependency.hpp`](../source/XYO/DllInjectSample/Dependency.hpp)
for the export-macro logic and [`fabricare.json`](../fabricare.json) for the
exact dependency and CRT settings.
