#ifndef TOOLS_HELPER
#define TOOLS_HELPER
#include <iostream>
#include <vector>
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

        
        
        class TempConfig{
            public:
                // Provide path file, without default
                TempConfig(std::string path_config_file = "config.json") : path_config_file_get(path_config_file){}


                
            private:
                std::string path_config_file_get;
        };
        
};

#endif