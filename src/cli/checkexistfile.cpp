#include "cli_terminal.h"
#include <fstream>
#include <filesystem>
std::vector<CoreCLI::data_check_file> CoreCLI::checkFileisExist(const std::vector<std::string> data){
    std::vector<CoreCLI::data_check_file> output;
    CoreCLI::data_check_file pak;
    for(size_t i = 0; i < data.size(); i++){

        if(!std::filesystem::exists(data[i])){
            pak.is_found=false;
            pak.path_file=data[i];
            output.push_back(pak);
            continue;
        }
        if(!std::filesystem::is_regular_file(data[i])){
            pak.is_regular=false;
            pak.path_file=data[i];
            output.push_back(pak);
            continue;
        }
        std::ifstream open(data[i]);
        if(!open.is_open()){
            pak.is_open=false;
            pak.path_file=data[i];
            output.push_back(pak);
            continue;
        }
        open.close();
        pak.is_found=true;
        pak.is_open=true;
        pak.is_regular=true;
        pak.path_file=data[i];

        output.push_back(pak);
    }
    return output;
}