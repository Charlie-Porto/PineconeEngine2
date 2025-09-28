#include "../../src/render_fns_SDL.hpp"
#include <pceSDL/pceSDL.hpp>

#include <pceLogger/pceLogger.hpp>

int main(int argc, const char* argv[])
{
    pce::parseLogLevelFromArgs(argc, argv);

    pce::CoreManager core_manager{};
    while (core_manager.running())
    {
        core_manager.doCorePreUpdate();
        pce::render::renderCircle(core_manager.renderer(),
                                  0,
                                  0,
                                  20,
                                  {255, 255, 255, 255},
                                  true);

        core_manager.doCorePostUpdate();
    }
    return EXIT_SUCCESS;
}
