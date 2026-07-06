#ifndef CDBUILD_H
#define CDBUILD_H
#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include "config/setting.h"
#include "json.hpp"
#include <filesystem>
/* ========== COMMAND CORE ========== */
// `"build"` command for build file
#define cd_build "build"

// `"--version"` command for show version core
#define cd_version "--version"

// Show how to use `core` command
//extern std::string cd_how_usage_cmd;

// Switch language
#define cd_switch_language "language"
/* ========== ERROR OUTPUT WHEN TYPE COMMAND ========== */
// Error return cmd
//extern std::string cd_input_type_error; 

// Error show cant find file
//extern std::string cd_input_type_path_error;

// Error show when user type "build" but dont type path file
//extern std::string cd_input_type_path_lost_error;

//extern std::string cd_input_type_path_error_file_extension;

//extern std::string cd_input_language_lost;

//extern std::string cd_input_error_language;



enum class SetLanguage{
    EN,
    VN
};
// English
//#include "PKG_EN/cmd/cdbuild_EN.h"
//#include "PKG_EN/cmd/errbuild_EN.h"

// Vietnamese
//#include "PKG_VN/cmd/cdbuild_VN.h"
//#include "PKG_VN/cmd/errbuild_VN.h"

using json = nlohmann::json;
extern json data;
inline std::unordered_map<std::string, SetLanguage> selection_language = {

    {"en", SetLanguage::EN}, // English

    {"vi", SetLanguage::VN}  // Vietnamese
};
void setupLang(const char* ARGV[]);
void setLanguage(const SetLanguage LS);
#endif