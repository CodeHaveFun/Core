#ifndef CDBUILD_EN_H
#define CDBUILD_EN_H
#include "cdbuild.h"
/*
=========================
======== ENGLISH ========
=========================
*/
/*Command core*/

inline void CDBUILD_EN(){
    cd_build = "build";
    cd_version = "--version";
    cd_switch_language = "language";
    cd_how_usage_cmd = R"(
Core Project | Usage commands
-----------------------------
Usage:
    |[COMMAND EXAMPLE                ]|[Explaining                 ]|
    | core                            | Show usage commands of Core |
    | core --version                  | Show version core now       |
    | core build <path source file>   | Compile source file         |
    | core language <your language>   | Switch language             |
)";
}
#endif