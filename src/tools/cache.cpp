#include "json.hpp"
#include "tools.h"
#include "debug.h"
#include <filesystem>
#include "color.h"
#include <fstream>
#include <vector>

// old read file
/* READ - CREATE PART */

/*
void tools::TempConfig::ReadConfigFile(){

    //Check file config exist?
    if(!std::filesystem::exists(path_config_file_get)){
        log(BRIGHT_RED("[FAILD]") << " Core could not found config file!" << " (" << path_config_file_get << ")")
        log(BRIGHT_WHITE(" Core will auto create config file."))
        CreateNewConfigFile(); // Create new
        ReadConfigFile(); // Read Again
        return;
    }
    std::ifstream fileopen(path_config_file_get);
    if(!fileopen.is_open()){
        log(BRIGHT_RED("[FAIL]") << " Core could not open config file!" << " (" << path_config_file_get << ")" << " no-recovery")
    }
    log(BRIGHT_GREEN("[OK]") << " Core opened config file." << " (" << path_config_file_get << ")")
    std::string content;
    log(" Core is parsing config file... (" << path_config_file_get << ")")
    while(std::getline(fileopen, content)){
        ParseConfigFile(content);
    }
    log(BRIGHT_GREEN("[OK]") << " Core parsed finish.")
}

void tools::TempConfig::CreateNewConfigFile(void){
    log(" Core creating new config file...")
    std::ofstream filenew(path_config_file_get);

    filenew << "debug:0\n";
    filenew << "language:no:''";

    filenew.close();
    log(BRIGHT_GREEN("[OK]") << " Core created new config file.")
}

/* PARSE CONFIG PART */
/*
Example Code Storage Table
input:  ` language:1:abc `
###|     0    | 1 |  2  |
0  | language | 1 | abc |
*/

/*
void tools::TempConfig::ParseConfigFile(const std::string text_line){
    std::string temp;
    std::vector<std::string> temp_code;
    if(text_line == "") return;
    for(size_t i = 0; i < text_line.length(); i++){
        // Meet ":" -> add temp and skip
        if(text_line[i] == ':'){
            temp_code.push_back(temp); // Add 
            temp.clear();
            continue;
        // Meet comment command, '#'
        }else if(text_line[i] == '#'){
             return; //out
        }

        temp += text_line[i];
        // if end charactar
        if(i == text_line.length() - 1){
            temp_code.push_back(temp);
        }

    }
    content_parse.push_back(temp_code);
}

void tools::TempConfig::GetConfig(){
    log(" Core is updating config from " << path_config_file_get << "...")
    // Scan rows
    for(size_t i = 0; i < content_parse.size(); i++){
        // Scan cols
        for(size_t j = 0; j < content_parse[i].size(); j++){
            // "debug command"
            if(content_parse[i][j] == "debug"){
                // debug command only have 2 elements. if its incorrect it not excuted
                if(content_parse[i].size() != 2){
                    log(BRIGHT_RED("[FAIL]") << " The debug command is insufficient or excessive.")
                    break;
                }
                if(content_parse[i][j + 1] != "0" &&
                    content_parse[i][j + 1] != "1"){
                    log(BRIGHT_RED("[FAIL]") << " Invalid value for debug.");
                    break;
                }

                debug_mode = (content_parse[i][j + 1] == "1");
            // language command need 3 elements
            }else if(content_parse[i][j] == "language"){
                if(content_parse[i].size() != 3){
                    log(BRIGHT_RED("[FAIL]") << " Invalid elements enough for language.")
                    break;
                }
                
            }

        }
    }
    log(BRIGHT_GREEN("[OK]") << "Core updated finish config.")
}
*/


