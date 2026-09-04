#include "cli_terminal.h"

void CoreCLI::register_default_commands_()
{
    if(!data_info_add_.empty())
        return;


    add_({
        .name = "build-cmd",
        .command = "build",
        .description = "Build a Core Project",
        .type = "subcommand"
    });


    add_({
        .name = "version-flag",
        .command = "--version",
        .description = "Show Core version",
        .type = "flag"
    });


    add_({
        .name = "help-flag",
        .command = "--help",
        .description = "Show usage",
        .type = "flag"
    });


    add_({
        .name = "output-build-cmd",
        .command = "--output",
        .description = "Set location for compiled output",
        .type = "flag",
        .allow_with = {"build-cmd"},
        .type_input = type_input::VALUE
    });
}