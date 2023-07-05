#include <CirrusApp.h>

CirrusApp::CirrusApp(unsigned int width, unsigned int height, std::string name): wnd(width, height, name)
{
}

CirrusApp::~CirrusApp()
{
}

void CirrusApp::Run()
{
    while(!glfwWindowShouldClose(wnd.GetWindow()))
    {
        glfwPollEvents();
    }
}
