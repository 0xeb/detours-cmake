#include <stdio.h>
#include <Windows.h>
#include <tchar.h>
#include <detours.h>

#define DLL_NAME _T("dllsample.dll")

//-------------------------------------------------------------------------
int main()
{
    STARTUPINFO si = {sizeof(STARTUPINFO)};
    PROCESS_INFORMATION pi;

    TCHAR BinDir[MAX_PATH];
    GetModuleFileName(nullptr, BinDir, _countof(BinDir));
    *_tcsrchr(BinDir, '\\') = '\0';
    SetCurrentDirectory(BinDir);

    BOOL ok = DetourCreateProcessWithDll(
        "dummy.exe", 
        nullptr, 
        nullptr, 
        nullptr, 
        FALSE, 
        0, 
        nullptr, 
        nullptr, 
        &si, 
        &pi, 
        DLL_NAME, 
        nullptr);

    _tprintf("Withdll: running the dummy program with " DLL_NAME "...%s\n", ok ? _T("ok!") : _T("failed!"));

    return 0;
}