#include <CirrusApp.h>
#include <BasicTriangle.h>
#include <CirrusValidation.h>

using namespace donut;

CirrusApp::CirrusApp(unsigned int width, unsigned int height, std::string name): volume("assets/bunny_cloud.vdb")
{
    nvrhi::GraphicsAPI api = nvrhi::GraphicsAPI::D3D12;
    deviceManager = app::DeviceManager::Create(api);

    app::DeviceCreationParameters deviceParams;

    deviceParams.enableDebugRuntime = true;
    deviceParams.enableNvrhiValidationLayer = true;

    if (!deviceManager->CreateWindowDeviceAndSwapChain(deviceParams, name.c_str()))
    {
        CirrusValidation::loge("CirrusApp: Failed to create window device and/or swapchain");
        return;
    }
}

CirrusApp::~CirrusApp()
{
    deviceManager->Shutdown();
    delete deviceManager;
}

void CirrusApp::Run()
{
    {
        BasicTriangle example(deviceManager);
        if (example.Init())
        {
            deviceManager->AddRenderPassToBack(&example);
            deviceManager->RunMessageLoop();
            deviceManager->RemoveRenderPass(&example);
        }
    }
}
