#include "cli_terminal.h"
#include "errors.h"
#include <stdexcept>
#include <filesystem>

void CoreCLI::add_(const info_add_ e)
{
    if(e.name.empty() || e.command.empty())
        throw std::invalid_argument(
            "Command name and command cannot be empty"
        );

    data_info_add_.push_back(e);
}


std::string CoreCLI::get_add_(
    const std::string name,
    const typeget type
)
{
    for(const auto& info : data_info_add_)
    {
        if(info.name != name)
            continue;

        if(type == typeget::command)
            return info.command;

        if(type == typeget::description)
            return info.description;

        if(type == typeget::type)
            return info.type;
    }

    return "";
}


std::vector<std::string> CoreCLI::get_allow_with_(
    const std::string name
)
{
    for(const auto& info : data_info_add_)
    {
        if(info.name == name)
            return info.allow_with;
    }

    return {};
}


std::vector<std::string> CoreCLI::get_subcommand_file(
    const std::vector<std::string>& array,
    int& pos
)
{
    std::vector<std::string> output;

    pos++;

    while(pos < static_cast<int>(array.size()))
    {
        if(!array[pos].empty() && array[pos][0] == '-')
        {
            pos--;
            break;
        }

        output.push_back(array[pos]);
        pos++;
    }

    return output;
}


bool CoreCLI::is_flag_allowed_(
    const std::string& name,
    const std::vector<std::string>& active_subcommands
)
{
    std::vector<std::string> allowed =
        get_allow_with_(name);

    // Không có allow_with = dùng được mọi nơi
    if(allowed.empty())
        return true;

    for(const auto& active : active_subcommands)
    {
        for(const auto& allow : allowed)
        {
            if(active == allow)
                return true;
        }
    }

    return false;
}


bool CoreCLI::validate_file_info_(
    const data_check_file& file_info,
    Errors& emsg
)
{
    if(!file_info.is_found)
    {
        emsg.err_print({
            .type = ErrorsType::ErrorsType_CLI,
            .error_code = "FILE_NOT_FOUND",
            .error_infomation =
                "File not found: '" +
                file_info.path_file + "'"
        });

        return false;
    }

    if(!file_info.is_regular)
    {
        emsg.err_print({
            .type = ErrorsType::ErrorsType_CLI,
            .error_code = "NOT_A_FILE",
            .error_infomation =
                "Path is not a regular file: '" +
                file_info.path_file + "'"
        });

        return false;
    }

    if(!file_info.is_open)
    {
        emsg.err_print({
            .type = ErrorsType::ErrorsType_CLI,
            .error_code = "CANNOT_OPEN_FILE",
            .error_infomation =
                "Cannot open file: '" +
                file_info.path_file + "'"
        });

        return false;
    }

    return true;
}


// ============================================================
// Kiểm tra token có tồn tại trong data_info_add_ hay không
// data_info_add_ chứa cả command và flag
// ============================================================

bool CoreCLI::is_a_command_(
    const std::string command,
    Errors& emsg
)
{
    for(const auto& info : data_info_add_)
    {
        if(info.command == command)
            return true;
    }

    emsg.err_print({
        .type = ErrorsType::ErrorsType_CLI,
        .error_code = "UNKNOWN_SYNTAX",
        .error_infomation =
            "'" + command +
            "' is not a command or flag of Core"
    });

    return false;
}


// ============================================================
// Parse
// ============================================================

void CoreCLI::ParseMain()
{
    Errors error_handler;

    std::vector<std::string> active_subcommands;

    register_default_commands_();

    size_t pos = 1;

    while(pos < internal_array_content.size())
    {
        const std::string& token =
            internal_array_content[pos];


        // ====================================================
        // Check token is existed?
        // ====================================================

        if(!is_a_command_(token, error_handler))
            return;


        // ====================================================
        // BUILD
        // ====================================================

        if(token == get_add_(
            "build-cmd",
            typeget::command
        ))
        {
            active_subcommands.push_back("build-cmd");

            int file_pos = static_cast<int>(pos);

            array_path_file_input =
                checkFileisExist(
                    get_subcommand_file(
                        internal_array_content,
                        file_pos
                    )
                );

            pos = file_pos;

            if(array_path_file_input.empty())
            {
                error_handler.err_print({
                    .type = ErrorsType::ErrorsType_CLI,
                    .error_code = "MISSING_BUILD_FILES",
                    .error_infomation =
                        "'build' command requires at least one file"
                });

                return;
            }

            for(const auto& file : array_path_file_input)
            {
                if(!validate_file_info_(
                    file,
                    error_handler
                ))
                    return;
            }

            pos++;
            continue;
        }


        // ====================================================
        // --version
        // ====================================================

        if(token == get_add_(
            "version-flag",
            typeget::command
        ))
        {
            if(!is_flag_allowed_(
                "version-flag",
                active_subcommands
            ))
            {
                error_handler.err_print({
                    .type = ErrorsType::ErrorsType_CLI,
                    .error_code = "FLAG_NOT_ALLOWED",
                    .error_infomation =
                        "'--version' cannot be used here"
                });

                return;
            }

            version_show();
            return;
        }


        // ====================================================
        // --help
        // ====================================================

        if(token == get_add_(
            "help-flag",
            typeget::command
        ))
        {
            if(!is_flag_allowed_(
                "help-flag",
                active_subcommands
            ))
            {
                error_handler.err_print({
                    .type = ErrorsType::ErrorsType_CLI,
                    .error_code = "FLAG_NOT_ALLOWED",
                    .error_infomation =
                        "'--help' cannot be used here"
                });

                return;
            }

            show_help(20);
            return;
        }


        // ====================================================
        // --output
        // ====================================================

        if(token == get_add_(
            "output-build-cmd",
            typeget::command
        ))
        {
            if(!is_flag_allowed_(
                "output-build-cmd",
                active_subcommands
            ))
            {
                error_handler.err_print({
                    .type = ErrorsType::ErrorsType_CLI,
                    .error_code = "FLAG_NOT_ALLOWED",
                    .error_infomation =
                        "'--output' can only be used with 'build'"
                });

                return;
            }

            pos++;

            // No value
            if(pos >= internal_array_content.size())
            {
                error_handler.err_print({
                    .type = ErrorsType::ErrorsType_CLI,
                    .error_code = "MISSING_FLAG_VALUE",
                    .error_infomation =
                        "'--output' requires a path"
                });

                return;
            }

            // Value is a flag
            if(internal_array_content[pos].empty() ||
               internal_array_content[pos][0] == '-')
            {
                error_handler.err_print({
                    .type = ErrorsType::ErrorsType_CLI,
                    .error_code = "MISSING_FLAG_VALUE",
                    .error_infomation =
                        "'--output' requires a path"
                });

                return;
            }

            // output path:
            // internal_array_content[pos]

            if(!std::filesystem::exists(internal_array_content[pos]) && !std::filesystem::is_directory(internal_array_content[pos])){
                error_handler.err_print({
                    .type=ErrorsType::ErrorsType_CLI,
                    .error_code="",
                    .error_infomation="'" + internal_array_content[pos] + "' is invaild output folder"
                });
                return;
            }

            path_output_folder = internal_array_content[pos]; // Update

            pos++;
            continue;
        }


        // ====================================================
        // Nếu token tồn tại nhưng chưa có xử lý
        // ====================================================

        error_handler.err_print({
            .type = ErrorsType::ErrorsType_CLI,
            .error_code = "UNHANDLED_SYNTAX",
            .error_infomation =
                "Core does not know how to handle '" +
                token + "'"
        });

        return;
    }


    // ========================================================
    // Result (TEST)
    // ========================================================

    for(const auto& file : array_path_file_input)
    {
        std::cout
            << "Source File Path: "
            << file.path_file;
        if(array_path_file_input.size() > 1) std::cout << ", ";
        
    }
    if(!array_path_file_input.empty())
        std::cout << "\n";
    if(!path_output_folder.empty()){
        std::cout << "Output Folder Path: " << path_output_folder << "\n";
    }else{
        std::cout << "Output Folder Path: None\n";
    }
}


// ============================================================
// Default commands
// ============================================================



// ============================================================
// Format allow_with
// ============================================================

std::string CoreCLI::format_allowed_commands_(
    const std::vector<std::string>& commands
)
{
    if(commands.empty())
        return "any command";

    std::string result;

    for(size_t i = 0; i < commands.size(); i++)
    {
        if(i > 0)
            result += ", ";

        result += "'" + commands[i] + "'";
    }

    return result;
}

