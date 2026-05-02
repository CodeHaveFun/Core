#ifndef LEXER_TOKEN_CORE_H
#define LEXER_TOKEN_CORE_H
#include <iostream>
using namespace std;
class LexerTokenCore{
    public:
        string LexerToken(string CodeTextLine);
    private:
        string AnalysisString(string INPUT_TOKEN);

};
#endif