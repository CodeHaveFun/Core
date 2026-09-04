#include "cli_terminal.h"
#include "command.h"
#include "errors.h"
#include "meta/version.h"
#include "terminal.h"
#include "color.h"
#include "tools.h"
#include "debug.h"

#include <cstddef>
#include <cstdint>


bool debug_mode = true;


void CoreCLI::InitTerminal(void){

    /* Operation System: Mircosoft Windows */
    #if defined (_WIN32)
        #include <windows.h>
        #include <consoleapi.h>
        #include <consoleapi2.h>
        #include <winnls.h>

        // Windows_Enable_ANSI(); // TODO: FIX in void

        if(GetConsoleCP() == CP_UTF8 && GetConsoleOutputCP() == CP_UTF8){
            CO_WHITE("Terminal was already in UTF-8 (Code Page: 65001)");
        }else{
            CO_WHITE("Terminal was in Input Code Page: " << GetConsoleCP() << " and Output Code Page: " << GetConsoleOutputCP());
            Windows_CHCP_UTF8();
            CO_GREEN("Terminal switched to UTF-8 (I/O Code Page: 65001)");
        }

    #endif
}



 