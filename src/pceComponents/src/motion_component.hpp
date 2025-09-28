#ifndef motion_component_hpp
#define motion_component_hpp

#include <glm/vec3.hpp>
#include <glm/ext/quaternion_double.hpp>

namespace pce {

struct Motion
{
    double speed;
    glm::dvec3 direction;
    glm::dvec3 velocity;
    double rotational_speed;
    glm::dvec3 rotational_axis;
    glm::dquat rotation_versor;
    double momentum;
    double duration;
    glm::dvec3 previous_resting_position;
    int stationary_counter;
};

} /* namespace pce */
#endif /* motion_component_hpp */
