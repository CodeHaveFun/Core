#include "frontend.h"
// Objective: Read each charaters in string
bool frontend::Front::isIdentify(const CoreUTF::LStringCharater char_input){
    return u_hasBinaryProperty(char_input, UCHAR_ID_START) || u_hasBinaryProperty(char_input, UCHAR_ID_CONTINUE) || char_input == U'_';
}

std::vector<info_token> frontend::Front::Lexical_Analysis(const unsigned long long line, const CoreUTF::LString CodeTextLine)
{
    CoreUTF::LString TempValue;
    std::vector<info_token> tokens;  
    info_token token;
    auto STk = [&](const TOKEN_CMD_CMM token_type, const CoreUTF::LString token_value){
        token.type = token_type;
        token.value = token_value;
        token.line = line;
        tokens.emplace_back(token);
    };
    auto CharC = [&](const std::string c){
        return CoreUTF::fromUTF8(c).char32At(0);
    };
    auto FlushTemp = [&]()
    {
        if (TempValue.length() == 0)
            return;
        token.line = line;
        
        auto it = KW_ENGLISH.find(CoreUTF::toUTF8(TempValue));

        if (it != KW_ENGLISH.end()) {
            //token.type = it->second;  
            //token.value = TempValue;  
            //tokens.emplace_back(token);
            STk(it->second,TempValue);
        } else {
            //token.type = TOKEN_CMD_CMM::TOKEN_IDENTIFIER;  
            //token.value = TempValue;        
            //tokens.emplace_back(token);
            STk(TOKEN_CMD_CMM::TOKEN_IDENTIFIER, TempValue);
        }

        TempValue.remove();
    };

    for (unsigned int i = 0; i < CodeTextLine.length(); i++)
    {
        CoreUTF::LStringCharater ch = CodeTextLine[i];

        if (isIdentify(ch))
        {
            TempValue.append(ch);
        }
        else
        {
            FlushTemp();
            if(ch == CharC("=")) STk(TOKEN_CMD_CMM::TOKEN_CMD_ASSIGN, ch);

            else if(ch == CharC("(")) STk(TOKEN_CMD_CMM::TOKEN_PAREN_OPEN, ch);
            else if(ch == CharC(")")) STk(TOKEN_CMD_CMM::TOKEN_PAREN_CLOSE, ch);
            else if(ch == CharC("[")) STk(TOKEN_CMD_CMM::TOKEN_BRACKET_OPEN, ch);
            else if(ch == CharC("]")) STk(TOKEN_CMD_CMM::TOKEN_BRACKET_CLOSE, ch);
            else if(ch == CharC("{")) STk(TOKEN_CMD_CMM::TOKEN_BRACE_OPEN, ch);
            else if(ch == CharC("}")) STk(TOKEN_CMD_CMM::TOKEN_BRACE_CLOSE, ch);
            else if(ch == CharC(",")) STk(TOKEN_CMD_CMM::TOKEN_COMMA, ch);
            else if(ch == CharC(";")) STk(TOKEN_CMD_CMM::TOKEN_SEMICOLON, ch);

            else if(ch == CharC(">")) STk(TOKEN_CMD_CMM::TOKEN_CMP_GREATER, ch);
            else if(ch == CharC("<")) STk(TOKEN_CMD_CMM::TOKEN_CMP_LESS, ch);
            //else if(ch == CharC(">=") || ch == CharC("=>")) STk(TOKEN_CMD_CMM::TOKEN_CMP_GREATER_EQUALS, ch); - not available (Only get 1 character)
            //else if(ch == CharC("=<") || ch == CharC("<=")) STk(TOKEN_CMD_CMM::TOKEN_CMP_LESS_EQUALS, ch); - not available (Only get 1 character)

            else if(ch == CharC("+")) STk(TOKEN_CMD_CMM::TOKEN_OP_PLUS, ch);
            else if(ch == CharC("-")) STk(TOKEN_CMD_CMM::TOKEN_OP_MINUS, ch);
            else if(ch == CharC("*")) STk(TOKEN_CMD_CMM::TOKEN_OP_ASTERISK, ch);
            else if(ch == CharC("/")) STk(TOKEN_CMD_CMM::TOKEN_OP_SLASH, ch);
            else if(ch == CharC("'")) STk(TOKEN_CMD_CMM::TOKEN_SINGLE_QUO, ch);
            else if(ch == CharC(std::string(1, '"'))) STk(TOKEN_CMD_CMM::TOKEN_DOUBLE_QUO, ch);
        }
    }
    

    
    
    FlushTemp();
    STk(TOKEN_CMD_CMM::TOKEN_NEWLINE, ""); // End-line
    return tokens;
}