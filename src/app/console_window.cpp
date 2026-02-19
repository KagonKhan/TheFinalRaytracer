#include "console_window.hpp"

#include <imgui.h>


void ConsoleWindow::render()
{
    ImGui::Begin(windowName());
    ImGui::Text("Bottom Panel Content");
    ImGui::End();
}
