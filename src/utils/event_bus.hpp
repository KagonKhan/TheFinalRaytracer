#ifndef TFR_UTILS_EVENT_BUS_HPP
#define TFR_UTILS_EVENT_BUS_HPP

#include "renderer/settings.hpp"

#include <dexode/EventBus.hpp>

namespace event
{

struct TextureIDUpdated { unsigned int id; };

struct SettingsChanged
{
    Settings newSettings;
};

}  // namespace events


class EventBus
{
public:
    static std::shared_ptr<dexode::EventBus> const& get() { return bus; }

    template <typename Event>
    static bool add(Event&& event) { return bus->postpone(std::forward<Event>(event)); }

    static std::size_t dispatch() { return bus->process(); }

private:
    inline static std::shared_ptr<dexode::EventBus> bus = std::make_shared<dexode::EventBus>();
};

#endif // TFR_UTILS_EVENT_BUS_HPP
