/* Core - MainTain | @CodeHaveFun */

#include <iostream>
#include "Frontend/InputGetFile.h"
#include "Frontend/LexerTokenCore.h"

using namespace std; 
int main(int argc, char const *argv[])
{
    InputGetFile IGF(argv[1]);
    LexerTokenCore LTC;
    if(!IGF.isOpen()){
        cout << "Cant open file" << endl;
    }
    string line;
    while(IGF.next(line)){
        string Codetemp = LTC.LexerToken(line);
        if(!Codetemp.empty()){
            cout << Codetemp << endl;
        }
    }
    return 0;
}

