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
#include "icu.h"

namespace frontend {
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

    class LexerTokenCore{
        public:
            CoreUTF::LString LexerToken(CoreUTF::LString CodeTextLine);
        private:
            CoreUTF::LString AnalysisString(CoreUTF::LString INPUT_TOKEN);
    };
}
// `InitStartCorex` to init all library and somethings modules before compiling
unsigned int InitStartCorex(const std::string& PATH_FILE);
void frontend_main(const int CMD_SIZE_IN,const char *CMD_STR_IN[]);
extern frontend::LexerTokenCore LTC;
extern frontend::InputGetFile IGF;
extern frontend::ValueOut ValueOut;
#endif