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
int main()
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&(PVOID&)real_Beep, my_Beep);
    auto error = DetourTransactionCommit();

    ::Beep(200, 1000);

    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourDetach(&(PVOID&)real_Beep, my_Beep);
    error = DetourTransactionCommit();

    return 0;
}