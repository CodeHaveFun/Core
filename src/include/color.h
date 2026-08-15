#ifndef _COLOR_TERMINAL_
#define _COLOR_TERMINAL_
#include <iostream>

namespace colorterminal
{
    // Reset
    constexpr const char* Reset = "\x1b[0m";
    constexpr const char* Default = "\x1b[39m";

    // Text - Normal
    constexpr const char* Black   = "\x1b[30m";
    constexpr const char* Red     = "\x1b[31m";
    constexpr const char* Green   = "\x1b[32m";
    constexpr const char* Yellow  = "\x1b[33m";
    constexpr const char* Blue    = "\x1b[34m";
    constexpr const char* Magenta = "\x1b[35m";
    constexpr const char* Cyan    = "\x1b[36m";
    constexpr const char* White   = "\x1b[37m";

    // Text - Bright
    constexpr const char* BrightBlack   = "\x1b[90m";
    constexpr const char* BrightRed     = "\x1b[91m";
    constexpr const char* BrightGreen   = "\x1b[92m";
    constexpr const char* BrightYellow  = "\x1b[93m";
    constexpr const char* BrightBlue    = "\x1b[94m";
    constexpr const char* BrightMagenta = "\x1b[95m";
    constexpr const char* BrightCyan    = "\x1b[96m";
    constexpr const char* BrightWhite   = "\x1b[97m";


    // Background - Normal
    constexpr const char* BgBlack   = "\x1b[40m";
    constexpr const char* BgRed     = "\x1b[41m";
    constexpr const char* BgGreen   = "\x1b[42m";
    constexpr const char* BgYellow  = "\x1b[43m";
    constexpr const char* BgBlue    = "\x1b[44m";
    constexpr const char* BgMagenta = "\x1b[45m";
    constexpr const char* BgCyan    = "\x1b[46m";
    constexpr const char* BgWhite   = "\x1b[47m";


    // Background - Bright
    constexpr const char* BgBrightBlack   = "\x1b[100m";
    constexpr const char* BgBrightRed     = "\x1b[101m";
    constexpr const char* BgBrightGreen   = "\x1b[102m";
    constexpr const char* BgBrightYellow  = "\x1b[103m";
    constexpr const char* BgBrightBlue    = "\x1b[104m";
    constexpr const char* BgBrightMagenta = "\x1b[105m";
    constexpr const char* BgBrightCyan    = "\x1b[106m";
    constexpr const char* BgBrightWhite   = "\x1b[107m";


    // Text styles
    constexpr const char* Bold      = "\x1b[1m";
    constexpr const char* Dim       = "\x1b[2m";
    constexpr const char* Italic    = "\x1b[3m";
    constexpr const char* Underline = "\x1b[4m";
    constexpr const char* Blink     = "\x1b[5m";
    constexpr const char* Reverse   = "\x1b[7m";
    constexpr const char* Hidden    = "\x1b[8m";
    constexpr const char* Strike    = "\x1b[9m";


    // Clear / cursor
    constexpr const char* ClearScreen = "\x1b[2J";
    constexpr const char* CursorHome = "\x1b[H";
}

/* --- COLOR WITH PRINT --- */

#define CO_RED(text) \
    std::cout << colorterminal::Red << text << colorterminal::Reset << '\n'

#define CO_GREEN(text) \
    std::cout << colorterminal::Green << text << colorterminal::Reset << '\n'

#define CO_BLUE(text) \
    std::cout << colorterminal::Blue << text << colorterminal::Reset << '\n'

#define CO_YELLOW(text) \
    std::cout << colorterminal::Yellow << text << colorterminal::Reset << '\n'

#define CO_CYAN(text) \
    std::cout << colorterminal::Cyan << text << colorterminal::Reset << '\n'

#define CO_MAGENTA(text) \
    std::cout << colorterminal::Magenta << text << colorterminal::Reset << '\n'

#define CO_WHITE(text) \
    std::cout << colorterminal::White << text << colorterminal::Reset << '\n'


// Bright color

#define CO_BRIGHT_RED(text) \
    std::cout << colorterminal::BrightRed << text << colorterminal::Reset << '\n'

#define CO_BRIGHT_GREEN(text) \
    std::cout << colorterminal::BrightGreen << text << colorterminal::Reset << '\n'

#define CO_BRIGHT_BLUE(text) \
    std::cout << colorterminal::BrightBlue << text << colorterminal::Reset << '\n'

#define CO_BRIGHT_YELLOW(text) \
    std::cout << colorterminal::BrightYellow << text << colorterminal::Reset << '\n'

#define CO_BRIGHT_CYAN(text) \
    std::cout << colorterminal::BrightCyan << text << colorterminal::Reset << '\n'

#define CO_BRIGHT_MAGENTA(text) \
    std::cout << colorterminal::BrightMagenta << text << colorterminal::Reset << '\n'

#define CO_BRIGHT_WHITE(text) \
    std::cout << colorterminal::BrightWhite << text << colorterminal::Reset << '\n'


// Background

#define CO_BG_RED(text) \
    std::cout << colorterminal::BgRed << text << colorterminal::Reset << '\n'

#define CO_BG_GREEN(text) \
    std::cout << colorterminal::BgGreen << text << colorterminal::Reset << '\n'

#define CO_BG_BLUE(text) \
    std::cout << colorterminal::BgBlue << text << colorterminal::Reset << '\n'


// Style

#define CO_BOLD(text) \
    std::cout << colorterminal::Bold << text << colorterminal::Reset << '\n'

#define CO_UNDERLINE(text) \
    std::cout << colorterminal::Underline << text << colorterminal::Reset << '\n'

#define CO_STRIKE(text) \
    std::cout << colorterminal::Strike << text << colorterminal::Reset << '\n'


/* --- COLOR WITHOUT PRINT --- */
// Normal color

#define RED(text) \
    colorterminal::Red << text << colorterminal::Reset

#define GREEN(text) \
    colorterminal::Green << text << colorterminal::Reset

#define BLUE(text) \
    colorterminal::Blue << text << colorterminal::Reset

#define YELLOW(text) \
    colorterminal::Yellow << text << colorterminal::Reset

#define CYAN(text) \
    colorterminal::Cyan << text << colorterminal::Reset

#define MAGENTA(text) \
    colorterminal::Magenta << text << colorterminal::Reset

#define WHITE(text) \
    colorterminal::White << text << colorterminal::Reset


// Bright color

#define BRIGHT_RED(text) \
    colorterminal::BrightRed << text << colorterminal::Reset

#define BRIGHT_GREEN(text) \
    colorterminal::BrightGreen << text << colorterminal::Reset

#define BRIGHT_BLUE(text) \
    colorterminal::BrightBlue << text << colorterminal::Reset

#define BRIGHT_YELLOW(text) \
    colorterminal::BrightYellow << text << colorterminal::Reset

#define BRIGHT_CYAN(text) \
    colorterminal::BrightCyan << text << colorterminal::Reset

#define BRIGHT_MAGENTA(text) \
    colorterminal::BrightMagenta << text << colorterminal::Reset

#define BRIGHT_WHITE(text) \
    colorterminal::BrightWhite << text << colorterminal::Reset


// Background

#define BG_RED(text) \
    colorterminal::BgRed << text << colorterminal::Reset

#define BG_GREEN(text) \
    colorterminal::BgGreen << text << colorterminal::Reset

#define BG_BLUE(text) \
    colorterminal::BgBlue << text << colorterminal::Reset


// Style

#define BOLD(text) \
    colorterminal::Bold << text << colorterminal::Reset

#define UNDERLINE(text) \
    colorterminal::Underline << text << colorterminal::Reset

#define STRIKE(text) \
    colorterminal::Strike << text << colorterminal::Reset

#endif