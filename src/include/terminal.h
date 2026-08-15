#ifndef TERMINAL_H
#define TERMINAL_H

/*
Operation System: Microsoft Windows

*/
#if defined (_WIN32)
    #include <windows.h>

    /*
    Active UTF-8 Code Page in Command Prompt or Powershell (CMD/PS).
    Code Page active: 65001 (UTF-8)
    
    Status: Good
    TODO: No
    */
    void Windows_CHCP_UTF8(void);

    /*
    ANSI : American National Standards Institute

    Enable ANSI Escape Codes in Command Prompt or Powershell (CMD/PS).
     WARNING :Some CMD/PS (old version, windows 7 and old OS) dont enable ANSI or dont support it.
    Need active Virtual Terminal to CMD/PS understand ANSI Escape Codes and if not, it can print error letter instead of color letter.
    
    Status: Dont works - Bad
    TODO: Fix active some key for registor windows
    */
    void Windows_Enable_ANSI();

#endif

#endif