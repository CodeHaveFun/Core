#ifndef _COMMAND_H
#define _COMMAND_H
#include <iostream>


// flag long `--`
#define FLAG_LONG "--"


// flag short `-`
#define FLAG_SHORT "-"

/*
@param as
*/
#define COMMAND_BUILD 1



typedef struct{
    int commands;
    std::string source_file;
    std::string source_output_file;
} CPROC;


#endif