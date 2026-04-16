#include "LexerTokenCore.h"

string LexerTokenCore::Clear(string CodeTextLine){
    /* Skip line comment (First comment of line, no code)*/
    if(CodeTextLine[0] == '|'){ 
        return ""; // No code
    }else{
        return CodeTextLine;
    }
}

string LexerTokenCore::LexerToken(string CodeTextLine){
    
}