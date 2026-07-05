#ifndef ERRBUILD_EN_H
#define ERRBUILD_EN_H
#include "cdbuild.h"
/*
=========================
======== ENGLISH ========
=========================
*/
inline void ERRBUILD_EN(){
    cd_input_type_error = " is not a command of Core :(";
    cd_input_type_path_error = ":( Core can not find file with path ";
    cd_input_type_path_lost_error = "BRO! Where is path soure file to compile?";
    cd_input_type_path_error_file_extension = "Oh no! Core accepts only files with the '.core' extension and does not accept files with other extensions.\n"
                                              "[TIP]: Change your file extension to '.core' (e.g., main.core, ABC.core).\n";
    cd_input_language_lost = "You're not entering the language? So does Core guess it automatically or something? 😐\n"
                             "[TIP]: Please enter it again, or if you aren't sure how, check the Core language table and then enter it. 😉\n";
    cd_input_error_language = "Core hasn't learned this language yet.\n"
                              "[TIP]: Please enter it again, or if you aren't sure how, check the Core language table and then enter it. 😉\n";
}
/* ---- ERROR OUTPUT WHEN TYPE COMMAND CLI ---- */

#endif