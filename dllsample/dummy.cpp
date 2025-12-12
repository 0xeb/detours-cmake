#include <stdio.h>
#include <windows.h>

//-------------------------------------------------------------------------
int main()
{
    ::Sleep(500);

    printf("Dummy program started...\n");
    ::Beep(200, 1000);
    printf("Dummy program ended...\n");
    return 0;
}