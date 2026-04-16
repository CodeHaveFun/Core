#ifndef LEXER_TOKEN_CORE_H
#define LEXER_TOKEN_CORE_H
#include <iostream>
using namespace std;
class LexerTokenCore{
    public:
        string Clear(string CodeTextLine);
        string LexerToken(string CodeTextLine);

};
#endif