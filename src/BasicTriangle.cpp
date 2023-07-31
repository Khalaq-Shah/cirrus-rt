#include <BasicTriangle.h>

using namespace donut;

bool BasicTriangle::Init()
{
    std::filesystem::path appShaderPath = app::GetDirectoryWithExecutable() / "shader" / app::GetShaderTypeName(GetDevice()->getGraphicsAPI());

    auto nativeFS = std::make_shared<vfs::NativeFileSystem>();
    engine::ShaderFactory shaderFactory(GetDevice(), nativeFS, appShaderPath);

    m_VertexShader = shaderFactory.CreateShader("shader.hlsl", "main_vs", nullptr, nvrhi::ShaderType::Vertex);
    m_PixelShader = shaderFactory.CreateShader("shader.hlsl", "main_ps", nullptr, nvrhi::ShaderType::Pixel);

    if (!m_VertexShader || !m_PixelShader)
    {
        return false;
    }

    m_CommandList = GetDevice()->createCommandList();

    return true;
}

void BasicTriangle::BackBufferResizing()
{
    m_Pipeline = nullptr;
}

void BasicTriangle::Render(nvrhi::IFramebuffer* framebuffer)
{
    if (!m_Pipeline)
    {
        nvrhi::GraphicsPipelineDesc psoDesc;
        psoDesc.VS = m_VertexShader;
        psoDesc.PS = m_PixelShader;
        psoDesc.primType = nvrhi::PrimitiveType::TriangleList;
        psoDesc.renderState.depthStencilState.depthTestEnable = false;

        m_Pipeline = GetDevice()->createGraphicsPipeline(psoDesc, framebuffer);
    }

    m_CommandList->open();

    nvrhi::utils::ClearColorAttachment(m_CommandList, framebuffer, 0, nvrhi::Color(0.f));

    nvrhi::GraphicsState state;
    state.pipeline = m_Pipeline;
    state.framebuffer = framebuffer;
    state.viewport.addViewportAndScissorRect(framebuffer->getFramebufferInfo().getViewport());

    m_CommandList->setGraphicsState(state);

    nvrhi::DrawArguments args;
    args.vertexCount = 3;
    m_CommandList->draw(args);

    m_CommandList->close();
    GetDevice()->executeCommandList(m_CommandList);
}