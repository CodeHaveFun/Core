#ifndef LEXICAL_HEADER
#define LEXICAL_HEADER

#include <iostream>

// I maybe use pipeline to process

class CoreLexical{

    public:

        CoreLexical(const std::string path_source_file) : source_file_build(path_source_file){}

        std::string ReadByLine(const std::string target_source);

    private:

        std::string source_file_build;

};

#endif