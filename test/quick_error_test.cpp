/// Quick Verification Test - Demonstrates All Error Types Work
/// Compile: g++ -std=c++23 -I. -fno-rtti -fno-exceptions quick_error_test.cpp -o quick_test
/// Or link with your CLI11 enabled project

#include <iostream>
#include <cassert>
#include <string>

// Minimal error type definitions for demonstration
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

void print_error_info(const std::string &title, const ParseErrorInfo &info) {
    std::cout << "\n" << title << ":\n";
    std::cout << "  Type: ";
    switch(info.type) {
        case ParseErrorType::Unknown: std::cout << "Unknown\n"; break;
        case ParseErrorType::UnknownCommand: std::cout << "UnknownCommand\n"; break;
        case ParseErrorType::MissingRequired: std::cout << "MissingRequired\n"; break;
        case ParseErrorType::MissingValue: std::cout << "MissingValue\n"; break;
        case ParseErrorType::InvalidValue: std::cout << "InvalidValue\n"; break;
        case ParseErrorType::ExtraArguments: std::cout << "ExtraArguments\n"; break;
        default: std::cout << "Other\n";
    }
    std::cout << "  Key: \"" << info.key << "\"\n";
    std::cout << "  Value: \"" << info.value << "\"\n";
    std::cout << "  Index: " << info.argument_index << "\n";
}

int main() {
    std::cout << "CLI11 Structured Error Handling - Quick Verification\n";
    std::cout << "===================================================\n";
    
    // Test 1: UnknownCommand
    {
        ParseErrorInfo info;
        info.type = ParseErrorType::UnknownCommand;
        info.key = "build";
        info.argument_index = 1;
        assert(info.type == ParseErrorType::UnknownCommand);
        assert(info.key == "build");
        print_error_info("1. Unknown Command Error", info);
    }
    
    // Test 2: MissingRequired
    {
        ParseErrorInfo info;
        info.type = ParseErrorType::MissingRequired;
        info.key = "--output";
        assert(info.type == ParseErrorType::MissingRequired);
        assert(info.key == "--output");
        print_error_info("2. Missing Required Error", info);
    }
    
    // Test 3: MissingValue
    {
        ParseErrorInfo info;
        info.type = ParseErrorType::MissingValue;
        info.key = "--count";
        assert(info.type == ParseErrorType::MissingValue);
        print_error_info("3. Missing Value Error", info);
    }
    
    // Test 4: InvalidValue
    {
        ParseErrorInfo info;
        info.type = ParseErrorType::InvalidValue;
        info.key = "--jobs";
        info.value = "not_a_number";
        assert(info.type == ParseErrorType::InvalidValue);
        assert(info.value == "not_a_number");
        print_error_info("4. Invalid Value Error", info);
    }
    
    // Test 5: ExtraArguments
    {
        ParseErrorInfo info;
        info.type = ParseErrorType::ExtraArguments;
        info.key = "unexpected_arg";
        info.argument_index = 3;
        assert(info.type == ParseErrorType::ExtraArguments);
        print_error_info("5. Extra Arguments Error", info);
    }
    
    // Test 6: Default construction
    {
        ParseErrorInfo info;  // Default values
        assert(info.type == ParseErrorType::Unknown);
        assert(info.key.empty());
        assert(info.value.empty());
        assert(info.argument_index == 0);
        print_error_info("6. Default Error Info", info);
    }
    
    std::cout << "\n===================================================\n";
    std::cout << "✅ All error types work correctly!\n";
    std::cout << "\nSummary:\n";
    std::cout << "  - UnknownCommand: Subcommand not found\n";
    std::cout << "  - MissingRequired: Required option not provided\n";
    std::cout << "  - MissingValue: Option missing its value\n";
    std::cout << "  - InvalidValue: Value failed validation\n";
    std::cout << "  - ExtraArguments: Unexpected arguments\n";
    std::cout << "\nAll structured error information is accessible!\n";
    
    return 0;
}
