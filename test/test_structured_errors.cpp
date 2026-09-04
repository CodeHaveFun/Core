#include <gtest/gtest.h>
#include <sstream>

#include "CLI/CLI.hpp"

// Test structured error information for ParseError

TEST(StructuredErrors, UnknownCommand) {
    CLI::App app("Test app");
    app.add_subcommand("build", "Build command");
    app.add_subcommand("run", "Run command");

    const char *argv[] = {"app", "buil"};
    int argc = 2;

    try {
        app.parse(argc, const_cast<char **>(argv));
        FAIL() << "Expected ParseError to be thrown";
    } catch(const CLI::ParseError &e) {
        // Verify structured error info
        EXPECT_EQ(e.type(), CLI::ParseErrorType::UnknownCommand);
        EXPECT_EQ(e.key(), "buil");
        EXPECT_NE(std::string(e.what()).find("buil"), std::string::npos);
    }
}

TEST(StructuredErrors, UnknownOption) {
    CLI::App app("Test app");
    app.add_flag("--verbose", "Verbose output");

    const char *argv[] = {"app", "--verbos"};
    int argc = 2;

    try {
        app.parse(argc, const_cast<char **>(argv));
        FAIL() << "Expected ParseError to be thrown";
    } catch(const CLI::ExtrasError &e) {
        // Unknown options end up as ExtrasError
        EXPECT_EQ(e.type(), CLI::ParseErrorType::ExtraArguments);
        EXPECT_EQ(e.key(), "--verbos");
        EXPECT_NE(std::string(e.what()).find("--verbos"), std::string::npos);
    } catch(const CLI::ParseError &e) {
        // Fallback for other error types
        EXPECT_NE(std::string(e.what()).find("--verbos"), std::string::npos);
    }
}

TEST(StructuredErrors, ExtraArguments) {
    CLI::App app("Test app");
    app.add_flag("--verbose", "Verbose output");

    const char *argv[] = {"app", "extra1", "extra2"};
    int argc = 3;

    try {
        app.parse(argc, const_cast<char **>(argv));
        FAIL() << "Expected ParseError to be thrown";
    } catch(const CLI::ExtrasError &e) {
        EXPECT_EQ(e.type(), CLI::ParseErrorType::ExtraArguments);
        EXPECT_EQ(e.key(), "extra1");  // First extra argument is the key
        EXPECT_NE(std::string(e.what()).find("not expected"), std::string::npos);
    }
}

TEST(StructuredErrors, MissingValue) {
    CLI::App app("Test app");
    auto *opt = app.add_option("--output", "Output file");

    const char *argv[] = {"app", "--output"};
    int argc = 2;

    try {
        app.parse(argc, const_cast<char **>(argv));
        FAIL() << "Expected ParseError to be thrown";
    } catch(const CLI::ArgumentMismatch &e) {
        // Missing value error
        EXPECT_NE(std::string(e.what()).find("--output"), std::string::npos);
    } catch(const CLI::ParseError &e) {
        // Fallback
        EXPECT_NE(std::string(e.what()).find("--output"), std::string::npos);
    }
}

TEST(StructuredErrors, InvalidValue) {
    CLI::App app("Test app");
    int num = 0;
    app.add_option("--jobs", num, "Number of jobs");

    const char *argv[] = {"app", "--jobs", "abc"};
    int argc = 3;

    try {
        app.parse(argc, const_cast<char **>(argv));
        FAIL() << "Expected ParseError to be thrown";
    } catch(const CLI::ConversionError &e) {
        // Conversion failed
        EXPECT_NE(std::string(e.what()).find("--jobs"), std::string::npos);
    } catch(const CLI::ParseError &e) {
        // Fallback
        EXPECT_NE(std::string(e.what()).find("--jobs"), std::string::npos);
    }
}

TEST(StructuredErrors, BackwardCompatibility) {
    CLI::App app("Test app");
    app.add_subcommand("build", "Build command");

    const char *argv[] = {"app", "unknown"};
    int argc = 2;

    try {
        app.parse(argc, const_cast<char **>(argv));
        FAIL() << "Expected ParseError to be thrown";
    } catch(const CLI::ParseError &e) {
        // Verify backward compatibility: what() should still work
        std::string error_msg = e.what();
        EXPECT_FALSE(error_msg.empty());
        EXPECT_NE(error_msg.find("unknown"), std::string::npos);
        
        // Verify new API works
        EXPECT_EQ(e.type(), CLI::ParseErrorType::UnknownCommand);
        EXPECT_EQ(e.key(), "unknown");
    }
}

TEST(StructuredErrors, ParseErrorInfoStructure) {
    CLI::ParseErrorInfo info;
    
    // Verify default values
    EXPECT_EQ(info.type, CLI::ParseErrorType::Unknown);
    EXPECT_TRUE(info.key.empty());
    EXPECT_TRUE(info.value.empty());
    EXPECT_EQ(info.argument_index, 0);
    
    // Verify we can set values
    info.type = CLI::ParseErrorType::UnknownCommand;
    info.key = "test";
    info.value = "testval";
    info.argument_index = 42;
    
    EXPECT_EQ(info.type, CLI::ParseErrorType::UnknownCommand);
    EXPECT_EQ(info.key, "test");
    EXPECT_EQ(info.value, "testval");
    EXPECT_EQ(info.argument_index, 42);
}

TEST(StructuredErrors, ErrorInfoAccessors) {
    CLI::ParseErrorInfo info;
    info.type = CLI::ParseErrorType::MissingValue;
    info.key = "--output";
    info.value = "";
    info.argument_index = 5;
    
    CLI::ParseError err("Test error", CLI::ExitCodes::InvalidError, info);
    
    // Verify accessors
    EXPECT_EQ(err.type(), CLI::ParseErrorType::MissingValue);
    EXPECT_EQ(err.key(), "--output");
    EXPECT_EQ(err.value(), "");
    EXPECT_EQ(err.argument_index(), 5);
    
    // Verify info() accessor
    const auto &info2 = err.info();
    EXPECT_EQ(info2.type, CLI::ParseErrorType::MissingValue);
    EXPECT_EQ(info2.key, "--output");
}

TEST(StructuredErrors, ErrorInfoDefaultConstruction) {
    CLI::ParseError err("Simple error", CLI::ExitCodes::InvalidError);
    
    // Verify default error info
    EXPECT_EQ(err.type(), CLI::ParseErrorType::Unknown);
    EXPECT_TRUE(err.key().empty());
    EXPECT_TRUE(err.value().empty());
    EXPECT_EQ(err.argument_index(), 0);
    EXPECT_NE(std::string(err.what()).find("Simple error"), std::string::npos);
}

TEST(StructuredErrors, ExtrasErrorWithMultipleArgs) {
    std::vector<std::string> args{"arg1", "arg2", "arg3"};
    CLI::ExtrasError err(args);
    
    // First argument should be in the key
    EXPECT_EQ(err.key(), "arg1");
    EXPECT_EQ(err.type(), CLI::ParseErrorType::ExtraArguments);
    
    // All args should be in the message
    std::string msg = err.what();
    EXPECT_NE(msg.find("arguments were"), std::string::npos);
}

TEST(StructuredErrors, ExtrasErrorWithSingleArg) {
    std::vector<std::string> args{"single"};
    CLI::ExtrasError err(args);
    
    // Verify singular form
    EXPECT_EQ(err.key(), "single");
    EXPECT_EQ(err.type(), CLI::ParseErrorType::ExtraArguments);
    
    std::string msg = err.what();
    EXPECT_NE(msg.find("argument was"), std::string::npos);
}
