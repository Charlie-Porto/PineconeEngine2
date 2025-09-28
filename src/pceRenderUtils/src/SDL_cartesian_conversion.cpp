#include "SDL_cartesian_conversion.hpp"


namespace pce {
namespace convert {


glm::ivec2 cartesianToSDL(const glm::ivec2& point)
{
    const int sdl_x = point.x + int(1000/2);
    const int sdl_y = -point.y + int(672/2);
    return glm::ivec2(sdl_x, sdl_y);
}


glm::ivec2 sdlToCartesian(const glm::ivec2& point)
{
    const int cart_x = point.x - int(1000/2);
    const int cart_y = -point.y + int(672/2);
    return glm::ivec2(cart_x, cart_y);
}


} /* namespace convert */
} /* namespace pce */
