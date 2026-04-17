#include "LexerTokenCore.h"

string LexerTokenCore::Clear(string CodeTextLine){
    /* Skip line comment (First comment of line, no code)*/
    if(CodeTextLine[0] == '|'){ 
        return ""; // No code
    }else{
        string CodeTemp;
        for(char Text : CodeTextLine){
            if(Text == '|') break;
            CodeTemp += Text;
        }
        return CodeTemp;
    }
}

string LexerTokenCore::LexerToken(string CodeTextLine){
    
}