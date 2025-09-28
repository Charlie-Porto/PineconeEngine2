#ifndef position_component_hpp
#define position_component_hpp

#include <utility>
#include <optional>

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

namespace pce {

struct Position
{
    glm::dvec3 com; //!< center of mass
    glm::dvec3 cam_rel_com; //!< center of mass if camera is the origin
    //std::pair<int, int> com_radar_pixel;
    std::optional<glm::ivec2> com_radar_pixel;
    double distance_from_camera;
};

} /* namespace pce */
#endif /* position_component_cpp */
