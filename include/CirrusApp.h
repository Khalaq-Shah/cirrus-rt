#pragma once
#include <Window.h>

class CirrusApp
{
public:
    /// @brief 
    /// @param width 
    /// @param height 
    /// @param name 
    CirrusApp(unsigned int width = 1920, unsigned int height = 1080, std::string name = "CirrusRT");
    ~CirrusApp();
    void Run();
private:
    Window wnd;
};