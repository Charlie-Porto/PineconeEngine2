#ifndef SDL_cartesian_conversion_hpp
#define SDL_cartesian_conversion_hpp

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
functions to convert SDL coordinates to cartesian coordinates, and vice versa.
-----------------------------------------------------------------*/

#include <glm/vec2.hpp>

namespace pce {
namespace convert {

glm::ivec2 cartesianToSDL(const glm::ivec2& point);
glm::ivec2 sdlToCartesian(const glm::ivec2& point);

} /* namespace convert */
} /* namespace pce */




#endif /* SDL_cartesian_conversion_hpp */
