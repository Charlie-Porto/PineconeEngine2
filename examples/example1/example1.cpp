#include <pceLogger/pceLogger.hpp>
#include <pceECS/pceECS.hpp>
#include <pce3dRenderSystems/RenderSystem.hpp>
#include <pce3dRenderSystems/OrderForRenderSystem.hpp>

int main(int argc, const char* argv[])
{
    pce::parseLogLevelFromArgs(argc, argv);
    std::string ln = "ex1";
    LOG_INFO(ln) << "Running: example1";

    using RendererSystemDummy = pce::RenderSystem<int>;
    pce::ControlPanel control{};

    pce::OrderForRenderSystem ofrs{ &control };
    RendererSystemDummy rs{ &control };

    LOG_INFO(ln) << "Done Running: example1";
    return 0;
}
