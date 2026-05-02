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
