#ifndef TERMINAL_SETUP_H
#define TERMINAL_SETUP_H
// If run on windows
#ifdef _WIN32
    #include <windows.h>
    // Run command prompt with UTF-8 (CHCP 65001)
    inline void TerminalUTF8(void){
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
        return;
    }
#endif

#endif