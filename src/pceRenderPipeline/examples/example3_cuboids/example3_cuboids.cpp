#include <pceSDL/pceSDL.hpp>
#include <pceLogger/pceLogger.hpp>
#include "../src/RenderPipeline.hpp"
#include <pceEntityForging/cuboid_forging.hpp>
#include <pceComponents/rigid_object_component.hpp>

int main(int argc, const char* argv[])
{
    using namespace std;
    using namespace pce;
    using namespace pce::forge;

    parseLogLevelFromArgs(argc, argv);
    CoreManager core_manager{};
    ControlPanel control{};
    RenderPipelineSDL render_pipeline{control, core_manager.renderer()};

    array<uint8_t, 4> color_white = {255, 255, 255, 255};
    array<uint8_t, 4> color_red = {255, 0, 0, 255};
    array<uint8_t, 4> color_green = {0, 255, 0, 255};
    array<uint8_t, 4> color_blue = {0, 0, 255, 255};

    CuboidForgingParams cfp0;
    // CONTINUE BELOW
    //cfp.

    //!< Create Cuboids
    const int axis_location = 40;

    while (core_manager.running())
    {   
        core_manager.doCorePreUpdate();
        render_pipeline.update(core_manager.frameEvents());
        core_manager.doCorePostUpdate();
    }   
    return EXIT_SUCCESS;
}
