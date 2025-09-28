#include <pceSDL/pceSDL.hpp>
#include <pceLogger/pceLogger.hpp>
#include "../src/RenderPipeline.hpp"
#include <pceEntityForging/sphere_forging.hpp>
#include <pceComponents/rigid_object_component.hpp>

int main(int argc, const char* argv[])
{
    pce::parseLogLevelFromArgs(argc, argv);
    pce::CoreManager core_manager{};
    pce::ControlPanel control{};
    pce::RenderPipelineSDL render_pipeline{control, core_manager.renderer()};

    //!< Create a balls
    //!< Origin
    const size_t start = 7;
    const size_t side_len = 15;
    for (size_t i=start; i!=side_len; ++i)
    {
        for (size_t j=start; j!=side_len; ++j)
        {
            for (size_t k=start; k!=side_len; ++k)
            {
                pce::forge::SphereForgingParams sfp0;
                sfp0.com = {i*20, j*20, k*20};
                sfp0.color = {static_cast<uint8_t>(i*13),
                              static_cast<uint8_t>(j*13),
                              static_cast<uint8_t>(k*13),
                              255};
                sfp0.radius = 5.0;
                uint32_t ball = pce::forge::forgeSphereEntity(control, sfp0);
            }
        }
    }
    

    while (core_manager.running())
    {   
        core_manager.doCorePreUpdate();
        render_pipeline.update(core_manager.frameEvents());
        core_manager.doCorePostUpdate();
    }   
    return EXIT_SUCCESS;
}
