#ifndef YARR_APP_APP_HPP
#define YARR_APP_APP_HPP

#include "main_window.hpp"
#include "renderer/renderer.hpp"

#include <GLFW/glfw3.h>

#include <memory>
#include <string>


class App
{
public:
    App(std::string const& title);
    ~App();

    void run(int fps = -1);

private:
    void initializeGLFW(std::string const& window_name);
    void initializeIMGUI();

    void startNewFrame();
    void finishFrame();

    GLFWwindow*                 window;
    std::unique_ptr<MainWindow> main_window;
    std::unique_ptr<Renderer>   renderer;
};

#endif
