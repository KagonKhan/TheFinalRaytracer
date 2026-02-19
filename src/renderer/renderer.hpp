#ifndef TEMPLATE_RENDERER_RENDERER_HPP
#define TEMPLATE_RENDERER_RENDERER_HPP

#include "image.hpp"
#include "utils/event_bus.hpp"

#include <string>


class Renderer
{
public:
    Renderer();

    void tick();

    Image          image {{800, 600}};
    unsigned char* data;

private:
    dexode::EventBus::Listener listener {EventBus::get()};

    Settings settings;
};

#endif // TEMPLATE_RENDERER_RENDERER_HPP
