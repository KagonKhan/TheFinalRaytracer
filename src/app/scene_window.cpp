#include "scene_window.hpp"

#include "utils/logger.hpp"

#include <imgui.h>

#include <cstdint>

SceneWindow::SceneWindow()
{
    listener.listen(
        [this] (event::TextureIDUpdated const& texture) {
            this->textureID = texture.id;
            LOG::INFO("Received texture ID");
        });
}

void SceneWindow::render()
{
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));

    ImGui::SetNextWindowSize(ImVec2(600, 400), ImGuiCond_FirstUseEver);
    ImGui::Begin(
        windowName(),
        nullptr,
        ImGuiWindowFlags_NoScrollbar |
        ImGuiWindowFlags_NoScrollWithMouse);
    ImVec2 avail = ImGui::GetContentRegionAvail();

    if (textureID.has_value()) {
        ImGui::Image((ImTextureID)(intptr_t)*textureID, avail);
    }

    // image.resize(ImGui::GetWindowContentRegionMax());
    // ImGui::Image((ImTextureID)(intptr_t)image.id(), image.size());
    ImGui::End();
    ImGui::PopStyleVar(1);
}
