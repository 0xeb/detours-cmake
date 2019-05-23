# Introduction

This is a project that uses [Microsoft's Detours](https://github.com/microsoft/detours) as a submodule with CMake.

# Building

After you clone this repository, initialize the Detours submodule like this:

```
git submodule udpdate --init --recursive
```

Follow the steps in the next section and after that, you will have a solution file (`*.sln`) that you can open with Visual Studio.

To build from the command line, type the following from the appropriate build folder:
```
cmake --build . --config Release
```

(Replace `Release` with `Debug` or any other configuration name).

The binaries will be in the build folder under `bin/[configuration_name]/`.

## Building for x86

```
mkdir build
cd build
cmake ..
```

## Building for x64

```
mkdir build64
cd build64
cmake -A x64 ..
```

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
