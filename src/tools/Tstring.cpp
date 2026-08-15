#include "tools.h"

std::string tools::Remove_Char(const std::string& text, const std::string& char_rm){
    std::string results;

    for(size_t i = 0; i < text.length(); i++)
    {
        bool keep = true; 

        for(size_t j = 0; j < char_rm.length(); j++)
        {
            if(text[i] == char_rm[j])
            {
                keep = false;
                break;
            }
        }

        if(keep)
            results += text[i];
    }

    return results;
}