#include "cdbuild.h"
#include "frontend.h"
// init
unsigned int InitStartCorex(const std::string& PATH_FILE){
    IGF.FileOpen(PATH_FILE); // give path for open file
    // IGF check file can open? ok -> continue | not ok -> return 1
    if(!IGF.isOpen()) {
        std::cout << cd_input_type_path_error << "'" << PATH_FILE << "'" << std::endl;
        return 1;
    }
    // Provide text code and line
    std::string CodeLineTemp; // Save data line temp 
    while(IGF.next(CodeLineTemp)){
        ValueOut.up_value_line();
        ValueOut.TextCode = CodeLineTemp;
        std::cout << ValueOut.line << "|" << ValueOut.TextCode << std::endl;
    }
    return 0;
}

void frontend_main(const int CMD_SIZE_IN, char const *CMD_STR_IN[]){
    // cmd show version
    if(strcmp(CMD_STR_IN[1], cd_version) == 0){
        std::cout << "Core Project | Version " << cd_version_now << std::endl;

    // cmd start build file
    }else if(strcmp(CMD_STR_IN[1], cd_build) == 0){
        InitStartCorex(CMD_STR_IN[2]);
    // if cmd 1 type error
    }else{
        // show error type cmd
        std::cout << "'" << CMD_STR_IN[1] << "'" << cd_input_type_error << std::endl;
    }
    return;
}

