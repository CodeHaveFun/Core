#include "windows.h"
#include "terminal.h"
#include <consoleapi.h>
#include <consoleapi2.h>
#include <winnls.h>


#if defined (_WIN32)
void Windows_CHCP_UTF8(void){
    /*
        Operation System: Microsoft Windows
        In terminal (especially Command Prompt and PowerShell low version) used fonts not supported unicode well.
        So we had to switch code page to UTF-8 by using 65001 code or typing `chcp 65001`

        TODO: Its OK!
    */
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}
void Windows_Enable_ANSI()
{
    /*
        Operation System: Microsoft Windows
        This void is enable ANSI for CMD/PS (Command Prompt/Powershell).

        TODO: This void can dont work well or dont work. Check for later! #1
    */
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    DWORD mode = 0;
    GetConsoleMode(hOut, &mode);

    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

    SetConsoleMode(hOut, mode);
}
#endif

