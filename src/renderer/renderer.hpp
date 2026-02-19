#ifndef TEMPLATE_RENDERER_RENDERER_HPP
#define TEMPLATE_RENDERER_RENDERER_HPP

#include "image.hpp"
#include "utils/event_bus.hpp"

#include <string>
#include <thread>

class Renderer
{
public:
    Renderer();

    void tick();

    Image          image {{1920, 1080}};
    unsigned char* data;

private:
    dexode::EventBus::Listener listener {EventBus::get()};

    Settings settings;

    std::jthread renderThread;
};

#endif // TEMPLATE_RENDERER_RENDERER_HPP
