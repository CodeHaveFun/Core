/* InputGetFile - Header | @CodeHaveFun*/

#pragma once
#ifndef INPUT_GET_FILE
#define INPUT_GET_FILE
#include <iostream>
#include <fstream>
using namespace std;
// create class InputGetFile (IGF)
class InputGetFile{
    private:
        ifstream FILE;
    public:
        // Open File
        InputGetFile(const string&path);
        // Check file
        bool isOpen();
        // Read next line
        bool next(string& line);
        // Clear space
        string Clear(string &Text);
        
};
#endif