#include "cdbuild.h"

/* ========== COMMAND CORE ========== */
// `"build"` command for build file
std::string cd_build;

// `"--version"` command for show version core
std::string cd_version;

// Core version now
std::string cd_version_now;

// Show how to use `core` command
std::string cd_how_usage_cmd;

// Switch language
std::string cd_switch_language;
/* ========== ERROR OUTPUT WHEN TYPE COMMAND ========== */
// Error return cmd
std::string cd_input_type_error; 

// Error show cant find file
std::string cd_input_type_path_error;

// Error show when user type "build" but dont type path file
std::string cd_input_type_path_lost_error;

std::string cd_input_type_path_error_file_extension;

std::string cd_input_language_lost;

std::string cd_input_error_language;

void setLanguage(const SetLanguage LS){
    switch(LS){
        case SetLanguage::EN:
            CDBUILD_EN();
            ERRBUILD_EN();
            break;
        case SetLanguage::VN:
            CDBUILD_VN();
            ERRBUILD_VN();
            break;
    }
}