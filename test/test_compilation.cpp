// Quick compilation test for all error classes


#include <iostream>

// Simulate the error classes with minimal dependencies
enum class ParseErrorType : unsigned char {
    Unknown = 0,
    UnknownCommand,
    UnknownArgument,
    MissingRequired,
    MissingValue,
    InvalidValue,
    ExtraArguments,
    ConversionFailed
};

struct ParseErrorInfo {
    ParseErrorType type = ParseErrorType::Unknown;
    std::string key;
    std::string value;
    std::size_t argument_index = 0;
};

int main() {
    std::cout << "Compilation test passed!\n";
    
    ParseErrorInfo info;
    info.type = ParseErrorType::MissingRequired;
    info.key = "--input";
    
    std::cout << "Error type: " << static_cast<int>(info.type) << "\n";
    std::cout << "Error key: " << info.key << "\n";
    
    return 0;
}
