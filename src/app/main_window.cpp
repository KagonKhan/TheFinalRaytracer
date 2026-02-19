#include "main_window.hpp"

#include <imgui.h>
#include <imgui_internal.h>

namespace
{

constexpr char const* DOCKSPACE_ID = "RootDockspace";

} // namespace

MainWindow::MainWindow()
{
    const ImGuiViewport* viewport     = ImGui::GetMainViewport();
    ImGuiID              dockspace_id = ImGui::GetID(DOCKSPACE_ID);

    ImGui::DockBuilderRemoveNode(dockspace_id);
    ImGui::DockBuilderAddNode(dockspace_id, ImGuiDockNodeFlags_DockSpace);
    ImGui::DockBuilderSetNodeSize(dockspace_id, viewport->Size);

    ImGuiID       main_dock  = dockspace_id;
    const ImGuiID LeftDock   = ImGui::DockBuilderSplitNode(main_dock, ImGuiDir_Left, 0.20f, nullptr, &main_dock);
    const ImGuiID BottomDock = ImGui::DockBuilderSplitNode(main_dock, ImGuiDir_Down, 0.25f, nullptr, &main_dock);
    const ImGuiID RightDock  = ImGui::DockBuilderSplitNode(main_dock, ImGuiDir_Right, 0.20f, nullptr, &main_dock);

    ImGui::DockBuilderDockWindow(EntityEditorWindow::windowName(), LeftDock);
    ImGui::DockBuilderDockWindow(SettingsWindow::windowName(), RightDock);
    ImGui::DockBuilderDockWindow(ConsoleWindow::windowName(), BottomDock);
    ImGui::DockBuilderDockWindow(SceneWindow::windowName(), main_dock);

    ImGui::DockBuilderFinish(dockspace_id);
}

void MainWindow::render()
{
    const ImGuiViewport* viewport     = ImGui::GetMainViewport();
    ImGuiID              dockspace_id = ImGui::GetID(DOCKSPACE_ID);

    ImGui::DockSpaceOverViewport(dockspace_id, viewport);

    settings.render();
    entity_editor.render();
    scene.render();
    console.render();
}
