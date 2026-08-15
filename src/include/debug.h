#ifndef DEBUG_H
#define DEBUG_H
#include "color.h"
extern bool debug_mode;

#define log(content) if(debug_mode) std::cout << BRIGHT_CYAN("[debug-mode]") << content << "\n";

#endif