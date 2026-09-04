#ifndef TOOLS_HELPER
#define TOOLS_HELPER
#include "core.h"
#include <iostream>
#include <vector>
#include "json.hpp"
class tools{
    public:
        /* 
        Remove Char
        (string) text : text which you want remove char in it
        (string) char_rm: text which you selection char to remove
        Example:
               text: "Hello World!"
            rm_char: "or"
             Return: "Hell Wld!"
        */
        std::string Remove_Char(const std::string& text, const std::string& char_rm);
        bool CheckText_StartWith(const std::string& text, const std::string& text_need_checked);
        
        /*
        Parse Package 
        */
        class ParsePKG{
            public:
                ParsePKG(std::string path) : source_pkg(path){}

                bool ParsePKG_Init();

            private:
                std::string source_pkg;
        };

        
        
        class ConfigureFile{
            private:
                std::string path_config_file_get;

            

            public:
                enum ErrorOpen{
                    NOT_FOUND_CONFIGURE_FILE,
                    CANNOT_OPEN_CONFIGURE_FILE,
                    SUCCESS
                };

                enum Retry{
                    RETRY_READ_FILE_COUNT = 3
                };

                // Provide path file, without default
                ConfigureFile(const std::string path_config_file = "config.json") : path_config_file_get(path_config_file){}

                ErrorOpen CheckConfigureFile();

                nlohmann::json ReadConfigureFile();
                
                void WriteConfigureFile(const nlohmann::json& data_write);

                void CreateNewConfigureFile();

                void Change_LastUsed_ConfigureFile(const std::string& name_package);
       
                bool Check_LastUsed_IsEmpty_ConfigureFile();

        };
        
};

#endif