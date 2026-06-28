#ifndef KW_EN_H
#define KW_EN_H

#include <map>
#include <iostream>
#include "../icu.h"
#include "../tokendefine.h"

/* 
PACKAGE ENGLISH COMMAND DICTIONARY | COMMON SYSTEM LANGUAGE 
*/

/* #### `English Commands Dictionary` <=> `Common System Language` */
const std::map<std::string, TOKEN_CMD_CMM> KW_ENGLISH = {


    // ==========================================
    // BASIC COMMANDS
    // ==========================================
    {"value", TOKEN_CMD_CMM::TOKEN_CMD_VAR},       // cmd init variable
    //{"=", TOKEN_CMD_CMM::TOKEN_CMD_ASSIGN},        // cmd assign value to variable
    {"print", TOKEN_CMD_CMM::TOKEN_CMD_PRINT},     // cmd print content in console (Terminal)
    {"input", TOKEN_CMD_CMM::TOKEN_CMD_INPUT},     // cmd get input from user

    // ==========================================
    // MATH OPERATORS: + - * /
    // ==========================================
    //{"+", TOKEN_CMD_CMM::TOKEN_OP_PLUS},           // operation plus
    //{"-", TOKEN_CMD_CMM::TOKEN_OP_MINUS},          // operation minus
    //{"*", TOKEN_CMD_CMM::TOKEN_OP_ASTERISK},       // operation multiply
    //{"/", TOKEN_CMD_CMM::TOKEN_OP_SLASH},          // operation divide

    // ==========================================
    // COMPARE OPERATORS: >, <, >=, <=, ==, and, or, not
    // ==========================================
    //{">", TOKEN_CMD_CMM::TOKEN_CMP_GREATER},       // compare greater than
    //{"<", TOKEN_CMD_CMM::TOKEN_CMP_LESS},          // compare less than
    //{"=>", TOKEN_CMD_CMM::TOKEN_CMP_GREATER_EQUALS}, // compare greater than or equal (type 1)
    //{">=", TOKEN_CMD_CMM::TOKEN_CMP_GREATER_EQUALS}, // compare greater than or equal (type 2)
    //{"<=", TOKEN_CMD_CMM::TOKEN_CMP_LESS_EQUALS},  // compare less than or equal (type 1)
    //{"=<", TOKEN_CMD_CMM::TOKEN_CMP_LESS_EQUALS},  // compare less than or equal (type 2)
    //{"==", TOKEN_CMD_CMM::TOKEN_CMP_EQUALS},       // compare equals
    {"and", TOKEN_CMD_CMM::TOKEN_CMP_AND},         // compare logical AND
    {"or", TOKEN_CMD_CMM::TOKEN_CMP_OR},           // compare logical OR
    {"not", TOKEN_CMD_CMM::TOKEN_CMP_NOT},         // compare logical NOT

    // ==========================================
    // BRACKETS & DELIMITERS
    // ==========================================
    //{"(", TOKEN_CMD_CMM::TOKEN_PAREN_OPEN},        // open parentheses
    //{")", TOKEN_CMD_CMM::TOKEN_PAREN_CLOSE},       // close parentheses
    //{"[", TOKEN_CMD_CMM::TOKEN_BRACKET_OPEN},      // open square bracket
    //{"]", TOKEN_CMD_CMM::TOKEN_BRACKET_CLOSE},     // close square bracket
    //{"{", TOKEN_CMD_CMM::TOKEN_BRACE_OPEN},        // open curly brace
    //{"}", TOKEN_CMD_CMM::TOKEN_BRACE_CLOSE},       // close curly brace
    //{",", TOKEN_CMD_CMM::TOKEN_COMMA},             // comma separator
    //{";", TOKEN_CMD_CMM::TOKEN_SEMICOLON},         // semicolon end statement

    // ==========================================
    // CONDITION COMMANDS: if, else if, else
    // ==========================================
    {"if", TOKEN_CMD_CMM::TOKEN_IF},               // condition command IF
    {"else if", TOKEN_CMD_CMM::TOKEN_ELSE_IF},     // condition command ELSE IF
    {"else", TOKEN_CMD_CMM::TOKEN_ELSE},           // condition command ELSE

    // ==========================================
    // LOOP COMMANDS: for, while
    // ==========================================
    {"for", TOKEN_CMD_CMM::TOKEN_FOR},             // loop command FOR
    {"while", TOKEN_CMD_CMM::TOKEN_WHILE},         // loop command WHILE

    // ==========================================
    // FUNCTION COMMANDS: void, return
    // ==========================================
    {"void", TOKEN_CMD_CMM::TOKEN_VOID},           // void function command
    {"return", TOKEN_CMD_CMM::TOKEN_RETURN}        // return command in void function
};

#endif