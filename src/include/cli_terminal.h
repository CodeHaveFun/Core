#ifndef CLI_TERMINAL
#define CLI_TERMINAL
#include "command.h"


/* CoreCLI
*/
class CoreCLI{
    public:

        /* Provide argc and argv
        Init CLI
        */
        CoreCLI(const int array_size, const char* array_content[]) 
            : internal_array_size(array_size), 
            internal_array_content(array_content){}

        /*
        Setup Terminal.
        IMPORTANT: Active UTF-8 to print extracly letter avoid error letter (in void)
        */
        void InitTerminal(void);

        /* Parse and excute command */
        void CommandProcessor();

        /* Return data for path I/O source file*/
        CPROC ReturnDataCommand();
    private:
        const int internal_array_size;
        const char* const* internal_array_content;


        void Flag(const std::string& type_flag, const std::string& command);
        void Build(const std::string& input_source_file, const std::string& output_source_file);
        
        
};

#endif