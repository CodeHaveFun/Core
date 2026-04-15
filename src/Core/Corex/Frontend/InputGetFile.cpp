/* @CodeHaveFun - InputGetFile */

#include "InputGetFile.h"
#include <fstream>
#include <string>
#include <sstream>
InputGetFile::InputGetFile(const string& PATH){
    FILE.open(PATH);
}
bool InputGetFile::isOpen(){
    return FILE.is_open();
}
bool InputGetFile::next(string &line){
    return (bool)getline(FILE, line);
}
string InputGetFile::Clear(string &Text){
    stringstream ClearLine(Text);
    string ReturnOutput, Word;
    while(ClearLine >> Word){
        if(!ReturnOutput.empty()){
            ReturnOutput += " ";
        }
        ReturnOutput += Word;
    }
    return ReturnOutput;
}