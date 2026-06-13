#include <pceSDL.hpp>
#include <pceLogger/pceLogger.hpp>

int main(int argc, const char* argv[])
{
    pce::parseLogLevelFromArgs(argc, argv);

    pce::CoreManager core_manager{};
    while (core_manager.running())
    {
        core_manager.doCorePreUpdate();
        core_manager.doCorePostUpdate();
    }
    return EXIT_SUCCESS;
}
