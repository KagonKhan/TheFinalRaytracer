#include "settings_window.hpp"

#include "utils/event_bus.hpp"

#include <imgui.h>

void SettingsWindow::render()
{
    ImGui::Begin(windowName());
    // ImGui::Text("pointer = %x", renderer.image.id());
    // ImGui::Text("size = %d x %d", (int)renderer.image.size().x, (int)renderer.image.size().y);

    if (ImGui::Checkbox("Generate noise", &settings.generateNoise)) {
        EventBus::add(event::SettingsChanged{settings});
    }

    ImGui::End();
}
