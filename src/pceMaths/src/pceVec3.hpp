#ifndef pceVec3_hpp
#define pceVec3_hpp

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
glm dvec3 with origin and direction
-----------------------------------------------------------------*/
#include <glm/vec3.hpp>

namespace pce {
namespace math {

struct pceVec3
{
    glm::dvec3 origin;
    glm::dvec3 direction;
};

} /* namespace math */
} /* namespace pce */
#endif /* pceVec3_hpp */
