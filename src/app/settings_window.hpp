#ifndef TFR_APP_SETTINGS_WINDOW_HPP
#define TFR_APP_SETTINGS_WINDOW_HPP

#include "renderer/settings.hpp"

#include <imgui.h>

#include <string>

class SettingsWindow
{
public:
    static const char* windowName() { return "Settings"; }

    void render();

private:
    Settings settings;
};

#endif // TFR_APP_SETTINGS_WINDOW_HPP
