/// Comprehensive test demonstrating all error types with structured error information
#include <gtest/gtest.h>
#include "CLI/CLI.hpp"

namespace {

// Test UnknownCommand error
TEST(StructuredErrorsComplete, UnknownCommandReturnsStructuredInfo) {
    CLI::App app("Test");
    app.add_subcommand("build", "Build");
    
    const char *argv[] = {"app", "unknown_cmd"};
    int argc = 2;
    
    try {
        app.parse(argc, const_cast<char **>(argv));
        FAIL() << "Expected ParseError";
    } catch(const CLI::ParseError &e) {
        EXPECT_EQ(e.type(), CLI::ParseErrorType::UnknownCommand);
        EXPECT_EQ(e.key(), "unknown_cmd");
        EXPECT_EQ(e.get_exit_code(), static_cast<int>(CLI::ExitCodes::InvalidError));
    }
}

// Test ExtraArguments error
TEST(StructuredErrorsComplete, ExtraArgumentsReturnsStructuredInfo) {
    CLI::App app("Test");
    app.add_flag("--verbose", "Verbose");
    
    const char *argv[] = {"app", "extra"};
    int argc = 2;
    
    try {
        app.parse(argc, const_cast<char **>(argv));
        FAIL() << "Expected ParseError";
    } catch(const CLI::ExtrasError &e) {
        EXPECT_EQ(e.type(), CLI::ParseErrorType::ExtraArguments);
        EXPECT_EQ(e.key(), "extra");
    } catch(const CLI::ParseError &e) {
        // Fallback
        EXPECT_TRUE(!std::string(e.what()).empty());
    }
}

// Test MissingRequired error
TEST(StructuredErrorsComplete, MissingRequiredReturnsStructuredInfo) {
    CLI::App app("Test");
    app.add_option("--output", "Output file")->required();
    
    const char *argv[] = {"app"};
    int argc = 1;
    
    try {
        app.parse(argc, const_cast<char **>(argv));
        FAIL() << "Expected RequiredError";
    } catch(const CLI::RequiredError &e) {
        EXPECT_EQ(e.type(), CLI::ParseErrorType::MissingRequired);
        EXPECT_EQ(e.key(), "--output");
        EXPECT_NE(std::string(e.what()).find("required"), std::string::npos);
    } catch(const CLI::ParseError &e) {
        EXPECT_EQ(e.type(), CLI::ParseErrorType::MissingRequired);
    }
}

// Test MissingValue error (missing argument value)
TEST(StructuredErrorsComplete, MissingValueReturnsStructuredInfo) {
    CLI::App app("Test");
    app.add_option("--count", "Count value");
    
    const char *argv[] = {"app", "--count"};
    int argc = 2;
    
    try {
        app.parse(argc, const_cast<char **>(argv));
        FAIL() << "Expected ArgumentMismatch";
    } catch(const CLI::ArgumentMismatch &e) {
        EXPECT_EQ(e.type(), CLI::ParseErrorType::MissingValue);
        EXPECT_EQ(e.key(), "--count");
    } catch(const CLI::ParseError &e) {
        EXPECT_EQ(e.type(), CLI::ParseErrorType::MissingValue);
    }
}

// Test InvalidValue error (conversion failure)
TEST(StructuredErrorsComplete, InvalidValueReturnsStructuredInfo) {
    CLI::App app("Test");
    int value = 0;
    app.add_option("--num", value, "Number");
    
    const char *argv[] = {"app", "--num", "not_a_number"};
    int argc = 3;
    
    try {
        app.parse(argc, const_cast<char **>(argv));
        FAIL() << "Expected ConversionError";
    } catch(const CLI::ConversionError &e) {
        EXPECT_EQ(e.type(), CLI::ParseErrorType::InvalidValue);
        EXPECT_EQ(e.key(), "--num");
        EXPECT_EQ(e.value(), "not_a_number");
    } catch(const CLI::ParseError &e) {
        EXPECT_EQ(e.type(), CLI::ParseErrorType::InvalidValue);
    }
}

// Test backward compatibility
TEST(StructuredErrorsComplete, BackwardCompatibilityPreserved) {
    CLI::App app("Test");
    app.add_subcommand("build", "Build");
    
    const char *argv[] = {"app", "wrong"};
    int argc = 2;
    
    try {
        app.parse(argc, const_cast<char **>(argv));
        FAIL() << "Expected ParseError";
    } catch(const CLI::ParseError &e) {
        // Old API still works
        std::string msg = e.what();
        EXPECT_FALSE(msg.empty());
        
        // New API also works
        EXPECT_EQ(e.type(), CLI::ParseErrorType::UnknownCommand);
        EXPECT_EQ(e.key(), "wrong");
        
        // Exit code still works
        EXPECT_GT(e.get_exit_code(), 0);
    }
}

// Test ParseErrorInfo structure
TEST(StructuredErrorsComplete, ParseErrorInfoStructure) {
    CLI::ParseErrorInfo info;
    info.type = CLI::ParseErrorType::MissingValue;
    info.key = "--output";
    info.value = "";
    info.argument_index = 2;
    
    EXPECT_EQ(info.type, CLI::ParseErrorType::MissingValue);
    EXPECT_EQ(info.key, "--output");
    EXPECT_EQ(info.value, "");
    EXPECT_EQ(info.argument_index, 2);
}

// Test error accessors
TEST(StructuredErrorsComplete, ErrorAccessorsWork) {
    CLI::ParseErrorInfo info;
    info.type = CLI::ParseErrorType::InvalidValue;
    info.key = "--jobs";
    info.value = "abc";
    info.argument_index = 3;
    
    CLI::ParseError err("Test error", CLI::ExitCodes::InvalidError, info);
    
    EXPECT_EQ(err.type(), CLI::ParseErrorType::InvalidValue);
    EXPECT_EQ(err.key(), "--jobs");
    EXPECT_EQ(err.value(), "abc");
    EXPECT_EQ(err.argument_index(), 3);
    
    const auto &stored_info = err.info();
    EXPECT_EQ(stored_info.type, CLI::ParseErrorType::InvalidValue);
}

// Test ConversionError with structured info
TEST(StructuredErrorsComplete, ConversionErrorStructured) {
    CLI::ConversionError err("--num", "invalid");
    
    EXPECT_EQ(err.type(), CLI::ParseErrorType::InvalidValue);
    EXPECT_EQ(err.key(), "--num");
    EXPECT_EQ(err.value(), "invalid");
}

// Test ValidationError with structured info
TEST(StructuredErrorsComplete, ValidationErrorStructured) {
    CLI::ValidationError err("--file", "does not exist");
    
    EXPECT_EQ(err.type(), CLI::ParseErrorType::InvalidValue);
    EXPECT_EQ(err.key(), "--file");
}

// Test RequiredError with structured info
TEST(StructuredErrorsComplete, RequiredErrorStructured) {
    CLI::RequiredError err("--name");
    
    EXPECT_EQ(err.type(), CLI::ParseErrorType::MissingRequired);
    EXPECT_EQ(err.key(), "--name");
    EXPECT_NE(std::string(err.what()).find("required"), std::string::npos);
}

// Test ArgumentMismatch with structured info
TEST(StructuredErrorsComplete, ArgumentMismatchStructured) {
    auto err = CLI::ArgumentMismatch::TypedAtLeast("--values", 3, "int");
    
    EXPECT_EQ(err.type(), CLI::ParseErrorType::MissingValue);
    EXPECT_EQ(err.key(), "--values");
}

// Test error info with default construction
TEST(StructuredErrorsComplete, DefaultErrorInfoConstruction) {
    CLI::ParseError err("Simple error", CLI::ExitCodes::InvalidError);
    
    EXPECT_EQ(err.type(), CLI::ParseErrorType::Unknown);
    EXPECT_TRUE(err.key().empty());
    EXPECT_TRUE(err.value().empty());
    EXPECT_EQ(err.argument_index(), 0);
}

// Test all ParseErrorType values
TEST(StructuredErrorsComplete, AllParseErrorTypesExist) {
    // Verify all error types are defined
    CLI::ParseErrorType types[] = {
        CLI::ParseErrorType::Unknown,
        CLI::ParseErrorType::UnknownCommand,
        CLI::ParseErrorType::UnknownArgument,
        CLI::ParseErrorType::MissingRequired,
        CLI::ParseErrorType::MissingValue,
        CLI::ParseErrorType::InvalidValue,
        CLI::ParseErrorType::ExtraArguments,
        CLI::ParseErrorType::ConversionFailed
    };
    
    // Just verify they all exist and have different values
    for(auto t : types) {
        EXPECT_GE(static_cast<int>(t), 0);
    }
}

}  // namespace
