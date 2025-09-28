#ifndef camera_hpp
#define camera_hpp

#include <glm/vec3.hpp>
#include <glm/ext/quaternion_double.hpp>

namespace pce {

struct Camera
{
    const glm::dvec3 default_view_direction = glm::dvec3(1, 0, 0);
    //const glm::dvec3 default_view_direction = glm::dvec3(0.0, -1.0, 0.0);
    //glm::dvec3 position = glm::dvec3(0.0, -100.0, 0.0);
    //glm::dvec3 position = glm::dvec3(0.0, 0.0, -30.0);
    glm::dvec3 position = glm::dvec3(0.0, 0.0, 0.0);
    //glm::dquat rotation_versor = glm::dquat(1.0, -1.0, 0, 0); //!< down
    glm::dquat rotation_versor = glm::dquat(1, 0, 0, 0);

    double focus_distance  = 20;
    double zoom_amount     = 1.0;
    double lense_curvature = 0.1;
    double lense_width     = 1.0;

    double rotation_impedence = 40; //!< quaternion w value. Higher number means fewer degrees per cycle
    double speed = 3; //!< move 3 units of distance each cycle (if moving)
};

} /* namespace pce */

#endif /* camera_hpp */
