#ifndef TFR_APP_CONSOLE_WINDOW_HPP
#define TFR_APP_CONSOLE_WINDOW_HPP

#include <string>

class ConsoleWindow
{
public:
    static const char* windowName() { return "Console"; }

    void render();
};

#endif // TFR_APP_CONSOLE_WINDOW_HPP
