#pragma once
#ifndef UTF8
#define UTF_8
#include <iostream>
#include "..\lib\Uni\unicode\unistr.h"
#include "..\lib\Uni\unicode\uchar.h"
namespace CoreUTF{
    // `LString`: Type string data of ICU (UTF-16)
    using LString = icu::UnicodeString;
    // ### UTF-8 | Convert UTF-8 (string) to UTF-16 (in ICU)
    // INPUTSTR UTF-8 (string) => return UTF-16 (in ICU)
    inline icu::UnicodeString fromUTF8(const std::string& INPUTSTR){
        return icu::UnicodeString::fromUTF8(INPUTSTR);
    }
    // ### UTF-8 | Convert UTF-16 (in ICU) to UTF-8 (string)
    // INPUT_UNI (UTF-16 in ICU) => OutputSTR (string)
    inline std::string toUTF8(const icu::UnicodeString& INPUT_UNI){
        std::string OutputSTR;
        INPUT_UNI.toUTF8String(OutputSTR);
        return OutputSTR;
    }
}
#endif