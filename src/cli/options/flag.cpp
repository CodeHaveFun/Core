#include "cli_terminal.h"
#include "color.h"
#include "debug.h"
#include "meta/version.h"
#include "meta/author.h"
#include "tools.h"


void CoreCLI::Flag(const std::string& type_flag, const std::string& command){
    if(type_flag == FLAG_LONG){
        // show version
        if(command == "version"){
            // Output: "Core Project XXXX BETA" or "Core Project XXXX"
            std::cout << 
                version::core_name <<  // Name
                " " << 
                version::core_version <<  // Version
                " " << 
                (version::core_beta == true ? "BETA" : "") <<  // Beta or none, true to active beta
                "\n";

        // Debug
        }else if(command == "debug"){
            log("Core was enable debug mode.")
            // Enable debug mode
            debug_mode = true;
        }else if(command == "no-debug"){
            log("Core was disable debug mode.")
            //Disable debug mode
            debug_mode = false;
        // load package language
        }else if(command == "load"){
            log("load PKGParse")
        }
    }

}