/* @CodeHaveFun - InputGetFile */

#include "frontend.h"
void frontend::InputGetFile::FileOpen(const std::string &path){
    FILE.open(path);
}
bool frontend::InputGetFile::isOpen(void){
    return FILE.is_open();
}
bool frontend::InputGetFile::next(std::string &line){
    return (bool)getline(FILE, line);
}
