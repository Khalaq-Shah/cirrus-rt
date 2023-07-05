#pragma once
#include <string>
#include <GLFW/glfw3.h>

class Window
{
public:
    Window(unsigned int width = 1920, unsigned int height = 1080, std::string name = "CirrusRT");
    ~Window();

    static void QuitCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

    GLFWwindow* GetWindow();
private:
    unsigned int _width, _height;
    std::string _name;

    GLFWwindow* window;
};