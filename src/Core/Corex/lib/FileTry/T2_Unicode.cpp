#include <iostream>
#include "unicode/unistr.h"

int main() {
    icu::UnicodeString s = icu::UnicodeString::fromUTF8("Xin chào");
    std::string utf8;
    s.toUTF8String(utf8);
    std::cout << utf8 << std::endl;
    return 0;
}