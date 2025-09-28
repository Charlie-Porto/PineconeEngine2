#ifndef Quadrilateral_hpp
#define Quadrilateral_hpp

#include <glm/vec2.hpp>

namespace pce {
namespace math {

struct Quadrilateral
{
    glm::dvec2 A; 
    glm::dvec2 B; 
    glm::dvec2 C; 
    glm::dvec2 D; 
};

} /* namespace math */
} /* namespace pce */
#endif /* Quadrilateral_hpp */
