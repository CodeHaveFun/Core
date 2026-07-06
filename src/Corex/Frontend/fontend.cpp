
#include "frontend.h"
void log(std::string ch_log){
    std::cout << "[LOG/DEBUG]: " << ch_log << std::endl;
    return;
}
// init
unsigned int Corex(const std::string& PATH_FILE){
    IGF.FileOpen(PATH_FILE); // give path for open file
    // IGF check file can open? ok -> continue | not ok -> return 1
    if(!IGF.isOpen()) {
        std::cout << data["CLI"]["error"]["input_type_path_error"] << "'" << PATH_FILE << "'" << std::endl;
        return 1;
    }
    // Provide text code and line
    std::string CodeLineTemp; // Save data line temp 
    while(IGF.next(CodeLineTemp)){
        ValueOut.up_value_line();
        ValueOut.TextCode = CodeLineTemp;
        //std::cout << ValueOut.line << "|" << ValueOut.TextCode << std::endl;
        // read each character on each lines
        auto tokens1 = LTC.Lexical_Analysis(ValueOut.line, CoreUTF::fromUTF8(ValueOut.TextCode));
        auto tokens = LTC.Token_Filter(tokens1);
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
    setupLang(CMD_STR_IN);
    std::cout <<"[DEBUG] Size user input (int): "<< CMD_SIZE_IN << std::endl;
    // if start command 'core' and dont type any command (total cmd is 1) -> show how to use
    if(CMD_SIZE_IN == 1){ //std::cout << how_usage_cmd << std::endl; // show usage
        for(auto& line_usage : data["CLI"]["usage"]){
            std::cout << line_usage.get<std::string>() << std::endl;
        }
        std::cout << std::endl;
    }else{
        // if start cmd with "--version" -> show version core now
        if(std::string(CMD_STR_IN[1]) == cd_version){
            std::cout << "Core Project | Version " << cd_version_now << std::endl;

        // cmd start build file
        }else if(std::string(CMD_STR_IN[1]) == cd_build){
            //InitStartCorex(CMD_STR_IN[2]);
            //check size enough 3 cmds? if enough -> start init Corex with path file input
            if(CMD_SIZE_IN == 3){
                std::string file_extension = lower_letter(CMD_STR_IN[2]);
                if(file_extension.ends_with(cd_file_extension)){
                    Corex(CMD_STR_IN[2]);
                }else{
                    std::cout<< data["CLI"]["error"]["input_type_path_error_file_extension"]["msg"].get<std::string>() <<std::endl;
                    std::cout<< data["CLI"]["error"]["input_type_path_error_file_extension"]["tip"].get<std::string>() <<std::endl;
                }
            }else {
                std::cout << data["CLI"]["error"]["input_type_path_lost_error"].get<std::string>() << std::endl;
            }
        }else if(std::string(CMD_STR_IN[1]) == cd_switch_language){
            if(CMD_SIZE_IN == 3){
                auto it = selection_language.find(lower_letter(std::string(CMD_STR_IN[2])));
                if(it != selection_language.end()){
                    setLanguage(it->second);
                }else{
                    std::cout << data["CLI"]["error"]["input_error_language"]["msg"].get<std::string>() << std::endl;
                    std::cout << data["CLI"]["error"]["input_error_language"]["tip"].get<std::string>() << std::endl;
                }
            }else{
                std::cout << data["CLI"]["error"]["input_language_lost"]["msg"].get<std::string>() << std::endl;
                std::cout << data["CLI"]["error"]["input_language_lost"]["tip"].get<std::string>() << std::endl;
            }
        // if cmd 1 type error
        }else{
            // show error type cmd
            std::cout << "'" << CMD_STR_IN[1] << "'" << data["CLI"]["error"]["input_type_error"].get<std::string>() << std::endl;
        }
    }
    return;
}

