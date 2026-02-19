#ifndef TFR_APP_SCENE_WINDOW_HPP
#define TFR_APP_SCENE_WINDOW_HPP

#include "utils/event_bus.hpp"

#include <string>

class SceneWindow
{
public:
    explicit SceneWindow();

    static const char* windowName() { return "Scene"; }

    void render();

private:
    dexode::EventBus::Listener  listener {EventBus::get()};
    std::optional<unsigned int> textureID {std::nullopt};
};

#endif // TFR_APP_SCENE_WINDOW_HPP
