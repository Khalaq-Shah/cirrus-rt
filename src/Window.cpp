#include <Window.h>

Window::Window(unsigned int width, unsigned int height, std::string name): _width(width), _height(height), _name(name)
{
    if (!glfwInit())
        exit(EXIT_FAILURE);

    window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, QuitCallback);
}

Window::~Window()
{
    glfwDestroyWindow(window);
 
    glfwTerminate();
}

void Window::QuitCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

GLFWwindow *Window::GetWindow()
{
    return window;
}
