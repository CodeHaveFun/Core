#ifndef VERSION_META
#define VERSION_META

namespace version {

    constexpr const char* core_name = "Core";
    constexpr const char* core_version = "0.0.1a";
    constexpr bool core_beta = true; // Beta version

    /* What OS build on */
    #if defined(_WIN32)
        constexpr const char* core_build_on = "Microsoft Windows";
    #elif defined(__linux__)
        constexpr const char* core_build_on = "Linux";
    #elif defined(__APPLE__)
        constexpr const char* core_build_on = "Apple (macOS/iOS)";
    #else
        constexpr const char* core_build_on = "Undetermined";
    #endif

    constexpr const char* core_build_date = __DATE__;
    constexpr const char* core_build_time = __TIME__;

    /* What compiler build on */
    #if defined(__clang__)
        constexpr const char* compiler_name_build_core = "Clang";
    #elif defined(__GNUC__)
        constexpr const char* compiler_name_build_core = "GCC";
    #elif defined(_MSC_VER)
        constexpr const char* compiler_name_build_core = "MSVC";
    #else
        constexpr const char* compiler_name_build_core = "Unknown";
    #endif



    #if __cplusplus >= 202302L
        constexpr const char* cpp_standard_version = "C++23";
    #elif __cplusplus >= 202002L
        constexpr const char* cpp_standard_version = "C++20";
    #elif __cplusplus >= 201703L
        constexpr const char* cpp_standard_version = "C++17";
    #elif __cplusplus >= 201402L
        constexpr const char* cpp_standard_version = "C++14";
    #elif __cplusplus >= 201103L
        constexpr const char* cpp_standard_version = "C++11";
    #else
        constexpr const char* cpp_standard_version = "C++98";
    #endif

    constexpr const char* license = "MIT";

} 

#endif