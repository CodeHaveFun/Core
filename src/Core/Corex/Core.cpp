/* Core - MainTain | @CodeHaveFun */

#include <iostream>
#include "Frontend/InputGetFile.h"
using namespace std; 
int main(int argc, char const *argv[])
{
    InputGetFile IGF(argv[1]);
    if(!IGF.isOpen()){
        cout << "Cant open file" << endl;
    }
    string line;
    while(IGF.next(line)){
        cout << IGF.Clear(line) << endl;
    }
    return 0;
}

