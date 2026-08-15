#include "tools.h"
#include <iostream>
#include <fstream>


bool tools::ParsePKG::ParsePKG_Init(){
    std::ifstream file_pkg(source_pkg);
    if(!file_pkg.is_open()) return false;

    
    
}