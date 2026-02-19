#ifndef TFR_APP_ENTITY_EDITOR_WINDOW_HPP
#define TFR_APP_ENTITY_EDITOR_WINDOW_HPP

#include <string>


class EntityEditorWindow
{
public:
    static const char* windowName() { return "EntityEditor"; }

    void render();
};

#endif // TFR_APP_ENTITY_EDITOR_WINDOW_HPP
