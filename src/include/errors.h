#ifndef ERRORS_H
#define ERRORS_H
#include <iostream>

enum class ErrorsType{
    ErrorsType_CLI,
    ErrorsType_Compile,
    ErrorsType_Runtime
};

struct ErrorsMessages{
    ErrorsType type;
    
    const std::string error_code;

    const std::string error_infomation;
};


class Errors{
    public:

        // call print error with format and exit program (default exit_program = true, change false to dont exit)
        void err_print(const ErrorsMessages info_errors, const bool exit_program = true);
};


#endif
