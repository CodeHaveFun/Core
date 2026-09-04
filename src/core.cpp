#include "core.h"
#include "color.h"
#include "debug.h"
#include "tools.h"

#include "cli_terminal.h"

/*
When starting to compile source file from command

# Old change
S1: Core reads config file.  (*.cfc - cfc: config core)
    - Load debug mode
    - Load installed language path (from OLP - Option Language Package) *.olp

# UPDATE CHANGE
TODO: Use JSON for configure file.

*/


/* --- MAIN PROGRAMMING --- */

int main(const int argc, const char* argv[]){
    // Default debug mode: false
    debug_mode = true;

    // start CLI with argc and argv
    CoreCLI CLI(argc, argv);

    // Init CLI
    CLI.InitTerminal();
    /*
    logs(PROCESS("Setuping configure program..."))
    // Start read config file with defualt
    tools::ConfigureFile Configure;

    int COUT_RETRY_TIME = 0;

    auto status = Configure.CheckConfigureFile();

    while(status == Configure.NOT_FOUND_CONFIGURE_FILE){
        if(COUT_RETRY_TIME >= Configure.RETRY_READ_FILE_COUNT){
            logs(BRIGHT_RED("[FAIL]")
                << "Core tried to find and create configure file in "
                << Configure.RETRY_READ_FILE_COUNT << " times");
            return 1;
        }

        Configure.CreateNewConfigureFile();
        COUT_RETRY_TIME++;

        status = Configure.CheckConfigureFile();
    }
    logs(OK("Finished setup configure program"))
    logs(PROCESS("Setuping and loading language program..."))
    */


    CLI.ParseMain();


    return 0;
}