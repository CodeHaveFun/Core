
#include "core.h"
#include "cli_terminal.h"
#include "debug.h"
#include "tools.h"
#include <cstdio>
/*
When starting to compile source file from command

S1: Core reads config file.  (*.cfc - cfc: config core)
    - Load debug mode
    - Load installed language path (from OLP - Option Language Package) *.olp

# UPDATE CHANGE
TODO: Use JSON instead of cfc for configure file.

*/


/* --- MAIN PROGRAMMING --- */

int main(const int argc, const char* argv[]){

    debug_mode = false;
    // start CLI
    CoreCLI CLI(argc, argv);

    // Init CLI
    CLI.InitTerminal();


    // process command (parse)
    CLI.CommandProcessor();

    // Start read config file with defualt
    tools::TempConfig file_config; 
    
    // Read Config File
    file_config.ReadConfigFile();

    // Get Info Config
    file_config.GetConfig();


    
    for(auto &raw : file_config.content_parse){
        for(auto &value : raw){
            std::cout << value << " ";
        }
        std::cout << "\n";
    }



    return 0;
}