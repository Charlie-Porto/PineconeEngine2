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
    const int axis_location = 40;
    //!< Origin
    pce::forge::SphereForgingParams sfp0;
    sfp0.com = {0, 0, 0};
    sfp0.color = {255, 255, 255, 255};
    sfp0.radius = 5.0;
    uint32_t white = pce::forge::forgeSphereEntity(control, sfp0);

    pce::forge::SphereForgingParams sfp1;
    sfp1.com = {0, 0, axis_location};
    sfp1.color = {0, 0, 255, 255};
    sfp1.radius = 5.0;
    int32_t blue = pce::forge::forgeSphereEntity(control, sfp1);

    pce::forge::SphereForgingParams sfp2;
    sfp2.com = {0, axis_location, 0};
    sfp2.color = {0, 255, 0, 255};
    sfp2.radius = 5.0;
    uint32_t green = pce::forge::forgeSphereEntity(control, sfp2);

    pce::forge::SphereForgingParams sfp3;
    sfp3.com = {axis_location, 0, 0};
    sfp3.color = {255, 0, 0, 255};
    sfp3.radius = 5.0;
    uint32_t red = pce::forge::forgeSphereEntity(control, sfp3);

    pce::forge::SphereForgingParams sfp4;
    sfp4.com = {-axis_location, 0, 0};
    sfp4.color = {120, 120, 0, 255};
    sfp4.radius = 5.0;
    uint32_t yellow = pce::forge::forgeSphereEntity(control, sfp4);

    pce::forge::SphereForgingParams sfp5;
    sfp5.com = {0, -axis_location, 0};
    sfp5.color = {0, 120, 120, 255};
    sfp5.radius = 5.0;
    uint32_t turquoise = pce::forge::forgeSphereEntity(control, sfp5);

    pce::forge::SphereForgingParams sfp6;
    sfp6.com = {0, 0, -axis_location};
    sfp6.color = {120, 0, 120, 255};
    sfp6.radius = 5.0;
    uint32_t magenta = pce::forge::forgeSphereEntity(control, sfp6);
    //uint32_t ball1 = pce::forge::forgeSphereEntity(control,
    //                                              5,
    //                                              glm::dvec3{0, 0, axis_location},
    //                                              {0, 0, 255, 255},
    //                                              {0, 0, 0},
    //                                              1,
    //                                              1);
    //uint32_t ball1b = pce::forge::forgeSphereEntity(control,
    //                                              5,
    //                                              glm::dvec3{0, 0, -axis_location},
    //                                              {120, 0, 120, 255},
    //                                              {0, 0, 0},
    //                                              1,
    //                                              1);
    //uint32_t ball2 = pce::forge::forgeSphereEntity(control,
    //                                              5,
    //                                              {axis_location, 0, 0},
    //                                              {255, 0, 0, 255},
    //                                              {0, 0, 0},
    //                                              1,
    //                                              1);
    //uint32_t ball2b = pce::forge::forgeSphereEntity(control,
    //                                              5,
    //                                              {-axis_location, 0, 0},
    //                                              {120, 120, 0, 255},
    //                                              {0, 0, 0},
    //                                              1,
    //                                              1);
    //uint32_t ball3 = pce::forge::forgeSphereEntity(control,
    //                                              5,
    //                                              {0, axis_location, 0},
    //                                              {0, 255, 0, 255},
    //                                              {0, 0, 0},
    //                                              1,
    //                                              1);
    //uint32_t ball4 = pce::forge::forgeSphereEntity(control,
    //                                              5,
    //                                              {0, -axis_location, 0},
    //                                              {0, 120, 120, 255},
    //                                              {0, 0, 0},
    //                                              1,
    //                                              1);


    while (core_manager.running())
    {   
        core_manager.doCorePreUpdate();
        render_pipeline.update(core_manager.frameEvents());
        core_manager.doCorePostUpdate();
    }   
    return EXIT_SUCCESS;
}
