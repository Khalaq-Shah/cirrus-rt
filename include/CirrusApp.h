#pragma once
#include <Window.h>
#include <donut/app/ApplicationBase.h>

class CirrusApp
{
public:
    CirrusApp(unsigned int width = 1920, unsigned int height = 1080, std::string name = "CirrusRT");
    ~CirrusApp();
    void Run();
private:
    Window wnd;
};