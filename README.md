# Introduction

This is a project that uses [Microsoft's Detours](https://github.com/microsoft/detours) as a submodule with CMake.

# Building

After you clone this repository, initialize the Detours submodule like this:

```
git submodule udpdate --init --recursive
```

Follow these steps to generate a solution file (`*.sln`) that you can open with Visual Studio:

- Configuring for x86 builds: `cmake -B build -A Win32`
- Configuring for x64 builds: `cmake -B build64 -A x64`

Now, to build from the command line, type the following from the appropriate build folder:

```batch
cd build or build64
cmake --build . --config Release
```

(Replace `Release` with `Debug` or any other configuration name).

The binaries will be in the build folder under `bin/[configuration_name]/`.

## Projects

This repository contains various projects:

### simple

The `simple` project is a standalone console program that uses Detours.

### dummy

This is a dummy project that calls the `Beep` API. This process, if executed alone, does nothing special. However, if we inject a Detours helper into it before starting it, it will behave differently.

### dllsample

This is a Detours helper DLL. When injected into a process, it installs hooks.

### runwithdll

This project leverages Detours' API `DetourCreateProcessWithDll` to run `dummy.exe` with the `dllsample.dll` (injected).

### lib_detours

This is the Detours static library itself.

### withdll
The `withdll` sample from the Detours' sample directory.
