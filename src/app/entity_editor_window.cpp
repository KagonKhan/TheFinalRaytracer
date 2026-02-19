#include "entity_editor_window.hpp"

#include <imgui.h>

void EntityEditorWindow::render()
{
    ImGui::Begin(windowName());
    ImGui::Text("Left Panel Content");
    ImGui::End();
}
