#include "cdbuild.h"
#include "frontend.h"
// init
unsigned int Corex(const std::string& PATH_FILE){
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
        //std::cout << ValueOut.line << "|" << ValueOut.TextCode << std::endl;
        // read each character on each lines
        auto tokens = LTC.Lexical_Analysis(ValueOut.line, CoreUTF::fromUTF8(ValueOut.TextCode));

        for (size_t i = 0; i < tokens.size(); i++) {
            const auto& token = tokens[i];
            
            std::cout << "[line:"<< token.line <<"|type:" << static_cast<int>(token.type) << "|value:" << CoreUTF::toUTF8(token.value) << "]";
            
        }
        std::cout << std::endl;
    }
    return 0;
}
std::string lower_letter(const std::string c){
    std::string output;
    for(int i = 0; i < c.length(); i++){
        if(isupper(c[i])){
            output += tolower(c[i]);
        }else{
            output += c[i];
        }
    }
    return output;
}
void frontend_main(const int CMD_SIZE_IN, char const *CMD_STR_IN[]){
    
    std::cout <<"[DEBUG] Size user input (int): "<< CMD_SIZE_IN << std::endl;
    // if start command 'core' and dont type any command (total cmd is 1) -> show how to use
    if(CMD_SIZE_IN == 1) std::cout << cd_how_usage_cmd << std::endl; // show usage
    else{
        // if start cmd with "--version" -> show version core now
        if(strcmp(CMD_STR_IN[1], cd_version) == 0){
            std::cout << "Core Project | Version " << cd_version_now << std::endl;

        // cmd start build file
        }else if(strcmp(CMD_STR_IN[1], cd_build) == 0){
            //InitStartCorex(CMD_STR_IN[2]);
            //check size enough 3 cmds? if enough -> start init Corex with path file input
            if(CMD_SIZE_IN == 3){
                std::string file_extension = lower_letter(CMD_STR_IN[2]);
                if(file_extension.ends_with(cd_file_extension)){
                    Corex(CMD_STR_IN[2]);
                }else{
                    std::cout<<"Oh no! Core accepts only files with the '.core' extension and does not accept files with other extensions."<<std::endl;
                    std::cout<<"Your '"<<CMD_STR_IN[2] <<"' is invalid."<<std::endl;
                }
            }
            else std::cout << cd_input_type_path_lost_error << std::endl;
        // if cmd 1 type error
        }else{
            // show error type cmd
            std::cout << "'" << CMD_STR_IN[1] << "'" << cd_input_type_error << std::endl;
        }
    }
    return;
}

