#include "cli_terminal.h"
#include "command.h"
#include "terminal.h"
#include "color.h"
#include "tools.h"
#include "debug.h"

#include <cstddef>

bool debug_mode = false;




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

void CoreCLI::CommandProcessor(){
    tools tools;
    // Scan elements in array
    for(size_t i = 0; i < internal_array_size; i++){
        std::string element_value = internal_array_content[i];

        if(element_value.starts_with("--"))
        {
            Flag(FLAG_LONG, tools.Remove_Char(element_value, FLAG_LONG));
        }
        // `-`: Short flag
        else if(element_value.starts_with("-"))
        {
            Flag(FLAG_SHORT, tools.Remove_Char(element_value, FLAG_SHORT));
        }else if(element_value.starts_with("build")){

        }
        
    }
}

