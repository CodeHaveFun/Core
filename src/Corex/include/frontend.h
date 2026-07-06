/*
==========Frontend Header File===========
*/
#pragma once
#ifndef FRONTEND_H
#define FRONTEND_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <variant>

#include "icu.h"
#include "tokendefine.h"
#include "config/setting.h"
#include "cdbuild.h"


#define LANGUAGE_SELECTION_EN
#ifdef LANGUAGE_SELECTION_EN
    #include "keywords/KW_EN.h"
#endif
#ifdef LANGUAGE_SELECTION_VN
    #include "keywords/KW_VN.h"
#endif

typedef struct{
    TOKEN_CMD_CMM type;
    CoreUTF::LString value;
    unsigned long long line;
} info_token;

namespace frontend{
    // Save textline and value line
    typedef struct{  
        // Save temp line text
        std::string TextCode;
        // line
        unsigned long long line;
        // increase line
        void up_value_line(void){
            line+=1;
        }
    } ValueOut;

    class InputGetFile{
        private:
            std::fstream FILE;  
        public:
            // Open File
            void FileOpen(const std::string&path);
            // Check file
            bool isOpen(void);
            // Read next line
            bool next(std::string& line);
        
    };
    // ### Contain void processing string | `CoreUTF:LString`
    class Front{
        public:

            std::vector<info_token> Lexical_Analysis(const unsigned long long line, const CoreUTF::LString CodeTextLine);
            std::vector<info_token> Filter_LV1(const std::vector<info_token>& ArrayToken);
            std::vector<info_token> Token_Filter(const std::vector<info_token>& ArrayToken);

            std::string get(std::string data);
        private:
            bool isIdentify(const CoreUTF::LStringCharater char_input);

    };
}
// `InitStartCorex` to init all library and somethings modules before compiling
unsigned int Corex(const std::string& PATH_FILE);
// `CMD_SIZE_IN`: Size commands fron user input | `CMD_STR_IN[]`: All command input 
void frontend_main(const int CMD_SIZE_IN,const char *CMD_STR_IN[]);
void log(std::string ch_log);
extern frontend::Front LTC;
extern frontend::InputGetFile IGF;
extern frontend::ValueOut ValueOut;
#endif