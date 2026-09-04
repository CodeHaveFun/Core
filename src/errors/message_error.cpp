
#include "errors.h"
#include "color.h"
#include <cstdlib>

void Errors::err_print(const ErrorsMessages info_errors, const bool exit_program){
    std::cout << BRIGHT_RED("[error]");
    switch(info_errors.type){
        case ErrorsType::ErrorsType_CLI:
            std::cout << " CLI ";
            break;
        case ErrorsType::ErrorsType_Compile:
            std::cout << " Compile ";
            break;
        case ErrorsType::ErrorsType_Runtime: 
            std::cout << " Runtime ";
            break;
        
    };
    if(info_errors.type != ErrorsType::ErrorsType_CLI) std::cout << "(ec:" << info_errors.error_code << "):";
    std::cout << "\n" << info_errors.error_infomation << "\n";
    std::cout << "Run 'core --help' to see more infomation." << "\n";
    if(exit_program) exit(1);
    else return;
}