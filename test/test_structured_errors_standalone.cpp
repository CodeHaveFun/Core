// Simple standalone test to verify structured error handling
// Compile with: g++ -std=c++23 -I. test_structured_errors_standalone.cpp -o test_errors
// Usage: ./test_errors [test_name]

#include "src/include/cli_terminal.h"  // Change path if needed
#include <iostream>
#include <cassert>

int main() {
    std::cout << "Testing CLI11 Structured Error Handling\n";
    std::cout << "========================================\n\n";

    // Test 1: ParseErrorType enum exists
    std::cout << "Test 1: ParseErrorType enum...\n";
    CLI::ParseErrorType type = CLI::ParseErrorType::UnknownCommand;
    assert(type == CLI::ParseErrorType::UnknownCommand);
    std::cout << "  ✓ ParseErrorType enum works\n\n";

    // Test 2: ParseErrorInfo struct exists and works
    std::cout << "Test 2: ParseErrorInfo struct...\n";
    CLI::ParseErrorInfo info;
    info.type = CLI::ParseErrorType::UnknownArgument;
    info.key = "test_key";
    info.value = "test_value";
    info.argument_index = 42;
    assert(info.type == CLI::ParseErrorType::UnknownArgument);
    assert(info.key == "test_key");
    assert(info.value == "test_value");
    assert(info.argument_index == 42);
    std::cout << "  ✓ ParseErrorInfo struct works\n\n";

    // Test 3: ParseError class stores and exposes error info
    std::cout << "Test 3: ParseError class with structured info...\n";
    CLI::ParseErrorInfo info2;
    info2.type = CLI::ParseErrorType::ExtraArguments;
    info2.key = "unknown_arg";
    info2.argument_index = 1;
    
    CLI::ParseError err("Test error message", CLI::ExitCodes::InvalidError, info2);
    assert(err.type() == CLI::ParseErrorType::ExtraArguments);
    assert(err.key() == "unknown_arg");
    assert(err.argument_index() == 1);
    assert(std::string(err.what()).find("Test error message") != std::string::npos);
    std::cout << "  ✓ ParseError accessors work\n\n";

    // Test 4: ParseError with default info
    std::cout << "Test 4: ParseError with default ParseErrorInfo...\n";
    CLI::ParseError err2("Simple error", CLI::ExitCodes::InvalidError);
    assert(err2.type() == CLI::ParseErrorType::Unknown);
    assert(err2.key().empty());
    assert(err2.value().empty());
    assert(err2.argument_index() == 0);
    std::cout << "  ✓ Default ParseErrorInfo works\n\n";

    // Test 5: ExtrasError with multiple arguments
    std::cout << "Test 5: ExtrasError with multiple arguments...\n";
    std::vector<std::string> args_list{"arg1", "arg2", "arg3"};
    CLI::ExtrasError extras_err(args_list);
    assert(extras_err.type() == CLI::ParseErrorType::ExtraArguments);
    assert(extras_err.key() == "arg1");
    assert(std::string(extras_err.what()).find("arguments were") != std::string::npos);
    std::cout << "  ✓ ExtrasError captures first argument\n\n";

    // Test 6: ExtrasError with single argument
    std::cout << "Test 6: ExtrasError with single argument...\n";
    std::vector<std::string> single_arg{"lonely"};
    CLI::ExtrasError single_err(single_arg);
    assert(single_err.type() == CLI::ParseErrorType::ExtraArguments);
    assert(single_err.key() == "lonely");
    assert(std::string(single_err.what()).find("argument was") != std::string::npos);
    std::cout << "  ✓ ExtrasError singular form works\n\n";

    // Test 7: Backward compatibility - what() still works
    std::cout << "Test 7: Backward compatibility...\n";
    std::string msg = err.what();
    assert(!msg.empty());
    assert(msg.find("Test error message") != std::string::npos);
    std::cout << "  ✓ what() method still returns error message\n\n";

    std::cout << "========================================\n";
    std::cout << "All tests passed! ✓\n";
    std::cout << "\nStructured error handling is working correctly.\n";
    
    return 0;
}
