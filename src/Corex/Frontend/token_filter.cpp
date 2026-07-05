#include "frontend.h"
/*
    | Token Array Input | -> [Scan Token | Connect token command | return (LV1)] -> [Scan Token | Check `'` and `"` then delete command, create | return (LV2)] -> OUTPUT

*/
std::vector<info_token> frontend::Front::Token_Filter(const std::vector<info_token>& ArrayToken){
    return Filter_LV1(ArrayToken);
}

std::vector<info_token> frontend::Front::Filter_LV1(const std::vector<info_token>& ArrayToken){
    std::vector<info_token> Results;
    info_token token_temp;
    bool continue_read = true;
    for(int i = 0; i < ArrayToken.size(); i++){
        const info_token key = ArrayToken[i];

        auto STk = [&](const TOKEN_CMD_CMM token_type, const CoreUTF::LString token_value){
            token_temp.type = token_type;
            token_temp.value = token_value;
            token_temp.line = key.line;
            Results.emplace_back(token_temp);
        };
        
        if(continue_read){
            if(i + 1 < ArrayToken.size()){
                info_token key_conti = ArrayToken[i + 1]; 
                
                switch(key.type){
                    // >=
                    case TOKEN_CMD_CMM::TOKEN_CMP_GREATER:
                        if(key_conti.type == TOKEN_CMD_CMM::TOKEN_CMD_ASSIGN){
                            STk(TOKEN_CMD_CMM::TOKEN_CMP_GREATER_EQUALS, ">=");
                            continue_read = false;
                        }
                        break;
                    // <=
                    case TOKEN_CMD_CMM::TOKEN_CMP_LESS:
                        if(key_conti.type == TOKEN_CMD_CMM::TOKEN_CMD_ASSIGN){
                            STk(TOKEN_CMD_CMM::TOKEN_CMP_LESS_EQUALS, "<=");
                            continue_read = false;
                        }
                        break;
                    // =>, =<, ==
                    case TOKEN_CMD_CMM::TOKEN_CMD_ASSIGN:
                        // =>
                        if(key_conti.type == TOKEN_CMD_CMM::TOKEN_CMP_GREATER){
                            STk(TOKEN_CMD_CMM::TOKEN_CMP_GREATER_EQUALS, "=>");
                            continue_read = false;
                        // =<
                        }else if(key_conti.type == TOKEN_CMD_CMM::TOKEN_CMP_LESS){
                            STk(TOKEN_CMD_CMM::TOKEN_CMP_LESS_EQUALS, "=<");
                            continue_read = false;
                        // ==
                        }else if(key_conti.type == TOKEN_CMD_CMM::TOKEN_CMD_ASSIGN){
                            STk(TOKEN_CMD_CMM::TOKEN_CMP_EQUALS, "==");
                            continue_read = false;
                        }
                        break;
                    // +=, ++
                    case TOKEN_CMD_CMM::TOKEN_OP_PLUS:
                        // +=
                        if(key_conti.type == TOKEN_CMD_CMM::TOKEN_CMD_ASSIGN){
                            STk(TOKEN_CMD_CMM::TOKEN_OP_PLUS_EQUAL, "+=");
                            continue_read = false;
                        // ++
                        }else if(key_conti.type == TOKEN_CMD_CMM::TOKEN_OP_PLUS){
                            STk(TOKEN_CMD_CMM::TOKEN_OP_PLUS_ONE, "++");
                            continue_read = false;
                        }
                        break;
                    // -=, --
                    case TOKEN_CMD_CMM::TOKEN_OP_MINUS:
                        if(key_conti.type == TOKEN_CMD_CMM::TOKEN_CMD_ASSIGN){
                            STk(TOKEN_CMD_CMM::TOKEN_OP_MINUS_EQUAL, "-=");
                            continue_read = false;
                        }else if(key_conti.type == TOKEN_CMD_CMM::TOKEN_OP_MINUS){
                            STk(TOKEN_CMD_CMM::TOKEN_OP_MINUS_ONE, "--");
                            continue_read = false;
                        }
                        break;
                    // *=
                    case TOKEN_CMD_CMM::TOKEN_OP_ASTERISK:
                        if(key_conti.type == TOKEN_CMD_CMM::TOKEN_CMD_ASSIGN){
                            STk(TOKEN_CMD_CMM::TOKEN_OP_ASTERISK_EQUAL, "*=");
                            continue_read = false;
                        }
                        break;
                    // /=
                    case TOKEN_CMD_CMM::TOKEN_OP_SLASH:
                        if(key_conti.type == TOKEN_CMD_CMM::TOKEN_CMD_ASSIGN){
                            STk(TOKEN_CMD_CMM::TOKEN_OP_SLASH_EQUAL, "/=");
                            continue_read = false;
                        }
                        break;

                }


            }
            if(continue_read) Results.emplace_back(key);
            
        }else{
            continue_read = true; // reset
        }
    }
    return Results;
}