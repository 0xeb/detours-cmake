#include <stdio.h>
#include <Windows.h>
#include <detours.h>

static auto real_Beep = ::Beep;

//-------------------------------------------------------------------------
static BOOL WINAPI my_Beep(DWORD dwFreq, DWORD dwDuration)
{
    printf("Beep(%u, %u)\n", dwFreq, dwDuration);
    return real_Beep(dwFreq, dwDuration);
}

//-------------------------------------------------------------------------
BOOL WINAPI DllMain(HINSTANCE hinst, DWORD dwReason, LPVOID reserved)
{
    LONG error;
    UNREFERENCED_PARAMETER(hinst);
    UNREFERENCED_PARAMETER(reserved);

    if (DetourIsHelperProcess())
        return TRUE;

    if (dwReason == DLL_PROCESS_ATTACH)
    {
        DetourRestoreAfterWith();

        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());
        DetourAttach(&(PVOID&)real_Beep, my_Beep);
        error = DetourTransactionCommit();
    }
    else if (dwReason == DLL_PROCESS_DETACH)
    {
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());
        DetourDetach(&(PVOID&)real_Beep, my_Beep);
        error = DetourTransactionCommit();
    }
    return TRUE;
}
