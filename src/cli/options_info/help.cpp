#include "cli_terminal.h"
#include "color.h"
#include "meta/version.h"
#include <cstdio>


/************** SHOW HELP ****************
*/

void CoreCLI::show_help(const int distance_exp){
    CoreCLI::version_show();


    std::string cmd_list;
    std::string flag_list;

    unsigned int numberof_subcmd = 0;
    unsigned int numberof_flag = 0;
    
    // Number of subcommand, flag 
    for(const info_add_& count : data_info_add_){
        if(count.type == "subcommand") numberof_subcmd++;
        if(count.type == "flag") numberof_flag++;
    }
    // find max lenght string
    auto findmax = [&](const std::vector<info_add_>& a) -> unsigned int {
        unsigned int max = 0;
        for(const info_add_& k : a){
            if(k.command.length() > max) max = k.command.length();
        }
        return max;
    };

    // Calculate space and plus distance_exp
    unsigned int max_lenght = findmax(data_info_add_);
    auto spacewh = [&](const unsigned int lenght) -> std::string {
        unsigned int totalmax = max_lenght + distance_exp;
        std::string spacewh = "";
        for(size_t i = 0; i < totalmax - lenght; i++){
            spacewh += " ";
        }
        return spacewh;
    };


    unsigned int i = 0;
    unsigned int count_subcmd = 0;
    unsigned int count_flag = 0;

    while(i < data_info_add_.size()){
        
        info_add_ e = data_info_add_[i];
        
        if(e.type == "subcommand"){
            count_subcmd++;
            // If it's not a end number
            if(count_subcmd < numberof_subcmd){
                 cmd_list += "    ├──> " + e.command + spacewh(e.command.length()) + "| " + e.description + "\n";
            }else{
                 cmd_list += "    └──> " + e.command + spacewh(e.command.length()) + "| " + e.description + "\n";
            }
        }
        if(e.type == "flag"){
            count_flag++;
            if(count_flag < numberof_flag){
                flag_list += "    ├──> " + e.command + spacewh(e.command.length()) + "| " + e.description + "\n";
            }else{
                flag_list += "    └──> " + e.command + spacewh(e.command.length()) + "| " + e.description + "\n";
            }
        }

        i++;
    }


    std::cout
    << "\nUSAGE:\n"
    << "    ├──> core [command] [option] ...\n"
    << "    ├──> core [command] [long option]\n"
    << "    └──> core [long option]\n\n";

    std::cout << "COMMAND:\n";
    std::cout << cmd_list << "\n";
    std::cout << "FLAG:\n";
    std::cout << flag_list << "\n";

    std::cout << "\n" << WARNING("The CLI is in development and can have errors during parsing.");

}