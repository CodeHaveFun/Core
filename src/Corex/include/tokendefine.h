#ifndef TOKEN_DEFINE_SYSTEM_H
#define TOKEN_DEFINE_SYSTEM_H

/* #### DEFINE TOKEN | SET SYSTEM COMMANDS LANGUAGE */
enum class TOKEN_CMD_CMM {
    // ==========================================
    // 1. TYPE DATA SYSTEM
    // ==========================================
    TOKEN_TYPE_INT,     // `TOKEN_TYPE_INT`: set when system identify type data is `INTEGER` of variable
    TOKEN_TYPE_FLOAT,   // `TOKEN_TYPE_FLOAT`: set when system identify type data is `FLOAT` of variable
    TOKEN_TYPE_BOOL,    // `TOKEN_TYPE_BOOL`: set when system identify type data is `BOOL` of variable
    TOKEN_TYPE_STRING,  // `TOKEN_TYPE_STRING`: set when system identify type data is `STRING` of variable

    // ==========================================
    // 2. LITERAL VALUES (giá trị cụ thể)
    // ==========================================
    TOKEN_LIT_INT,      // `TOKEN_LIT_INT`: set when system identify literal is integer number (ex: 123)
    TOKEN_LIT_FLOAT,    // `TOKEN_LIT_FLOAT`: set when system identify literal is float number (ex: 3.14)
    TOKEN_LIT_STRING,   // `TOKEN_LIT_STRING`: set when system identify literal is string (ex: "Hello")
    TOKEN_LIT_BOOL,     // `TOKEN_LIT_BOOL`: set when system identify literal is boolean (true/false)

    // ==========================================
    // 3. COMPARE OPERATORS: >, <, >=, <=, ==, and, or, not
    // ==========================================
    TOKEN_CMP_GREATER,              // `TOKEN_CMP_GREATER`: set when system identify compare is `>`
    TOKEN_CMP_LESS,                 // `TOKEN_CMP_LESS`: set when system identify compare is `<`
    TOKEN_CMP_GREATER_EQUALS,       // `TOKEN_CMP_GREATER_EQUALS`: set when system identify compare is `>=` or `=>`
    TOKEN_CMP_LESS_EQUALS,          // `TOKEN_CMP_LESS_EQUALS`: set when system identify compare is `<=` or `=<`
    TOKEN_CMP_EQUALS,               // `TOKEN_CMP_EQUALS`: set when system identify compare is `==`
    TOKEN_CMP_AND,                  // `TOKEN_CMP_AND`: set when system identify compare is `AND`
    TOKEN_CMP_OR,                   // `TOKEN_CMP_OR`: set when system identify compare is `OR`
    TOKEN_CMP_NOT,                  // `TOKEN_CMP_NOT`: set when system identify compare is `NOT`

    // ==========================================
    // 4. MATH OPERATORS: + - * /
    // ==========================================
    TOKEN_OP_PLUS,      // `TOKEN_OP_PLUS`: set when system identify operation is `+`
    TOKEN_OP_MINUS,     // `TOKEN_OP_MINUS`: set when system identify operation is `-`
    TOKEN_OP_ASTERISK,  // `TOKEN_OP_ASTERISK`: set when system identify operation is `*`
    TOKEN_OP_SLASH,     // `TOKEN_OP_SLASH`: set when system identify operation is `/`

    // ==========================================
    // 5. BASIC COMMANDS
    // ==========================================
    TOKEN_CMD_VAR,      // `TOKEN_CMD_VAR`: set when user type command init variable (`value` or `var`)
    TOKEN_CMD_ASSIGN,   // `TOKEN_CMD_ASSIGN`: set when user type `=` command to assign
    TOKEN_CMD_PRINT,    // `TOKEN_CMD_PRINT`: set when user type print command to print content in console (Terminal)
    TOKEN_CMD_INPUT,    // `TOKEN_CMD_INPUT`: set when user type input command to get input from user

    // ==========================================
    // 6. BRACKETS & DELIMITERS
    // ==========================================
    TOKEN_PAREN_OPEN,   // `TOKEN_PAREN_OPEN`: set when open `(`
    TOKEN_PAREN_CLOSE,  // `TOKEN_PAREN_CLOSE`: set when close `)`
    TOKEN_BRACKET_OPEN, // `TOKEN_BRACKET_OPEN`: set when open `[`
    TOKEN_BRACKET_CLOSE,// `TOKEN_BRACKET_CLOSE`: set when close `]`
    TOKEN_BRACE_OPEN,   // `TOKEN_BRACE_OPEN`: set when open `{`
    TOKEN_BRACE_CLOSE,  // `TOKEN_BRACE_CLOSE`: set when close `}`
    TOKEN_COMMA,        // `TOKEN_COMMA`: set when user type `,` to separate list
    TOKEN_SEMICOLON,    // `TOKEN_SEMICOLON`: set when user type `;` to end statement
    TOKEN_NEWLINE,      // `TOKEN_NEWLINE`: set when system identify new line `\n`

    // ==========================================
    // 7. IDENTIFIER
    // ==========================================
    TOKEN_IDENTIFIER,   // `TOKEN_IDENTIFIER`: set when system identify name of variable or function

    // ==========================================
    // 8. CONDITION COMMANDS: if, else if, else
    // ==========================================
    TOKEN_IF,           // `TOKEN_IF`: set when user type command of condition with `IF` command
    TOKEN_ELSE_IF,      // `TOKEN_ELSE_IF`: set when type command of condition with `ELSE IF` command after starting `IF` command
    TOKEN_ELSE,         // `TOKEN_ELSE`: set when type command of condition with `ELSE` command after start `IF` or `ELSE IF` command

    // ==========================================
    // 9. LOOP COMMANDS: for, while
    // ==========================================
    TOKEN_FOR,          // `TOKEN_FOR`: set when user type command of loop with `FOR` command
    TOKEN_WHILE,        // `TOKEN_WHILE`: set when user type command of loop with `WHILE` command

    // ==========================================
    // 10. FUNCTION COMMANDS: void, return
    // ==========================================
    TOKEN_VOID,         // `TOKEN_VOID`: set when user type command of void function with `VOID` command
    TOKEN_RETURN,       // `TOKEN_RETURN`: set when user type command of void function with `RETURN` command in `VOID` command

    // ==========================================
    // 11. SPECIAL TOKENS
    // ==========================================
    TOKEN_EOF,          // `TOKEN_EOF`: set when system reach end of file (End Of File)
    TOKEN_UNKNOWN       // `TOKEN_UNKNOWN`: set when system cannot identify token (error)
};

#endif