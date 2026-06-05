/* Core - MainTain | @CodeHaveFun */

#include <iostream>
#include "include\frontend.h"
// Frontend
frontend::InputGetFile IGF;
frontend::LexerTokenCore LTC;
frontend::ValueOut ValueOut;
int main(int argc, char const *argv[])
{
    frontend_main(argc,argv);
    /*
    frontend::InputGetFile IGF(argv[1]);
    frontend::LexerTokenCore LTC;
    if(!IGF.isOpen()){
        std::cout << "Cant open file" << std::endl;
    }
    std::string line;
    while(IGF.next(line)){
        std::string Codetemp = LTC.LexerToken(line);
        if(!Codetemp.empty()){
            std::cout << Codetemp << std::endl;
        }
    }
    return 0;
    */
}

