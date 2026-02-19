#ifndef TFR_APP_MAIN_WINDOW_HPP
#define TFR_APP_MAIN_WINDOW_HPP

#include "console_window.hpp"
#include "entity_editor_window.hpp"
#include "scene_window.hpp"
#include "settings_window.hpp"

class MainWindow
{
public:
    explicit MainWindow();
    void render();

private:
    SceneWindow        scene;
    SettingsWindow     settings;
    EntityEditorWindow entity_editor;
    ConsoleWindow      console;
};

#endif // TFR_APP_MAIN_WINDOW_HPP
