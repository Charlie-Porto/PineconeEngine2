#include <pceLogger/pceLogger.hpp>

#include "../../src/raster_functions.hpp"


namespace{
constexpr const char* log_name = "test_raster_fns";
}



int main(int argc, const char* argv[])
{
    pce::parseLogLevelFromArgs(argc, argv);
    LOG_DEBUG(log_name) << "Testing Raster Functions...";

    const int xc = 0;
    const int yc = 0;
    const int r = 5;

    const std::vector<glm::ivec2> points = pce::raster::rasterizeCircle(xc, yc, r);
    for (const auto& p : points)
    {
        std::cout << '\n' << p.x << ", " << p.y << '\n';
    }

    return EXIT_SUCCESS;
}
