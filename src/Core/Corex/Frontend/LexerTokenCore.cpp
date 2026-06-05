#include "frontend.h"
// DEMO


CoreUTF::LString frontend::LexerTokenCore::AnalysisString(CoreUTF::LString INPUT_TOKEN){
    return CoreUTF::LString("[") + INPUT_TOKEN + CoreUTF::LString("]");
}

CoreUTF::LString frontend::LexerTokenCore::LexerToken(CoreUTF::LString CodeTextLine){
    CoreUTF::LString TokenTemp;
    CoreUTF::LString CodeOUTPUT;

    for(size_t i = 0; i < CodeTextLine.length(); i++) {
        UChar32 ch = CodeTextLine[i];
        
        if(!u_isspace(ch)) {
            TokenTemp += ch;
        } else {
            if(!TokenTemp.isEmpty()) {
                CodeOUTPUT += AnalysisString(TokenTemp);
                TokenTemp.remove();
            }
        }
    }
    
    if(!TokenTemp.isEmpty()) 
        CodeOUTPUT += AnalysisString(TokenTemp);
    
    return CodeOUTPUT;
}