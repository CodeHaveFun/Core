#ifndef CLI_TERMINAL
#define CLI_TERMINAL
#include "command.h"
#include <functional>
#include <minwindef.h>
#include <string>
#include <vector>


/* CoreCLI
*/
class CoreCLI{
    public:

        /* Provide argc and argv
        Init CLI
        */
        CoreCLI(const int array_size, const char* array_content[]) {
            for(size_t i = 0; i < array_size; i++){
                internal_array_content.push_back(array_content[i]);
            }
        }

        /*
        Setup Terminal.
        IMPORTANT: Active UTF-8 to print extracly letter avoid error letter (in void)
        */
        void InitTerminal(void);


        void ParseMain();


    private:
        std::vector<std::string> internal_array_content;

        enum class type_input{
            VALUE,
            ACTIVE,
            NON
        };
        struct info_add_{
            std::string name;
            std::string command;
            std::string description="";
            std::string type;
            std::vector<std::string> allow_with = {};
            type_input type_input = type_input::NON;
        };
        std::vector<info_add_> data_info_add_;
        enum class typeget{
            command,
            description,
            type
        };
        void add_(const info_add_ e);

        std::string get_add_(const std::string name, const typeget a);

        //---------------------------------------------------
        static std::vector<std::string> get_subcommand_file(const std::vector<std::string>& array, int& pos);


        struct data_check_file{
            std::string path_file="";
            bool is_regular=false;
            bool is_found=false;
            bool is_open=false;
        };

        void version_show();
        void show_help(const int distance_exp);
        
        std::vector<data_check_file> array_path_file_input;
        std::string path_output_folder;
        std::vector<data_check_file> checkFileisExist(const std::vector<std::string> data);
        
        // ✓ NEW METHODS: allow_with support and validation
        std::vector<std::string> get_allow_with_(const std::string name);
        bool is_flag_allowed_(const std::string& flag_name, const std::vector<std::string>& active_subcommands);
        bool validate_file_info_(const data_check_file& file_info, class Errors& emsg);
        void register_default_commands_();
        std::string format_allowed_commands_(const std::vector<std::string>& commands);
        bool is_a_command_(const std::string command, Errors& emsg);
        
};

#endif