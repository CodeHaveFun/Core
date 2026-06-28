#ifndef CDBUILD_H
#define CDBUILD_H
/*Command core*/
// `"build"` command for build file
#define cd_build "build"
// `"--version"` command for show version core
#define cd_version "--version"
// Core version now
#define cd_version_now "0.0.1 [DEMO]"


// file extension allow
#define cd_file_extension ".core"

// Show how to use `core` command
inline constexpr const char* cd_how_usage_cmd = R"(
Core Project | Usage commands
-----------------------------
Usage:
    [COMMAND EXAMPLE               ]|[Explaining                 ]
    core                            | Show usage commands of Core
    core --version                  | Show version core now  
    core build <path source file>   | Compile source file
)";

/* ---- ERROR OUTPUT WHEN TYPE COMMAND ---- */
// Error return cmd
#define cd_input_type_error " is not a command of Core :("
// Error show cant find file
#define cd_input_type_path_error ":( Core can not find file with path "
// Error show when user type "build" but dont type path file
#define cd_input_type_path_lost_error "BRO! Where is path soure file to compile?"
#endif