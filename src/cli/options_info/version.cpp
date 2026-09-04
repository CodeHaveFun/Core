#include "cli_terminal.h"
#include "meta/version.h"
#include "color.h"

void CoreCLI::version_show(){
    // [DATE-TIME | Built on Microsoft Windows with GCC C++23]
    // Core X.X.XA
    std::cout << "[" 
        << version::core_build_date << "-" << version::core_build_time << " | " \
        << "Built on " << version::core_build_on << " with " \
        << version::compiler_name_build_core << " " <<version::cpp_standard_version \
        << "]" << "\n";

    std::cout << version::core_name 
    << " " << version::core_version 
    << " " 
    << ((version::core_beta == true) ? \
    std::string(colorterminal::BrightMagenta) + "BETA" + std::string(colorterminal::Reset) \
    : \
    std::string(colorterminal::BrightGreen) + "STABLE" + std::string(colorterminal::Reset)) << "\n";

}
