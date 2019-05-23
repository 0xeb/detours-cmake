#include <stdio.h>
#include <Windows.h>

//-------------------------------------------------------------------------
int main()
{
    ::Sleep(500);

    printf("Dummy program started...\n");
    ::Beep(200, 1000);
    printf("Dummy program ended...\n");
    return 0;
}