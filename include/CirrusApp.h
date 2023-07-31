#pragma once
#include <donut/app/ApplicationBase.h>
#include <Volume.h>

class CirrusApp
{
public:
    CirrusApp(unsigned int width = 1920, unsigned int height = 1080, std::string name = "CirrusRT");
    ~CirrusApp();
    void Run();
private:
    donut::app::DeviceManager* deviceManager;
    Volume volume;
};