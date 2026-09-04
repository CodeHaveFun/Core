#include "tools.h"
#include <cstddef>

std::string tools::Remove_Char(
    const std::string& text,
    const std::string& char_rm)
{
    std::string results = text;

    size_t pos = 0;

    while ((pos = results.find(char_rm, pos)) != std::string::npos)
    {
        results.erase(pos, char_rm.length());
    }

    return results;
}
bool tools::CheckText_StartWith(
    const std::string& text,
    const std::string& text_need_checked)
{
    if(text.size() < text_need_checked.size())
        return false;

    for(size_t i = 0; i < text_need_checked.size(); i++){
        if(text[i] != text_need_checked[i])
            return false;
    }

    return true;
}