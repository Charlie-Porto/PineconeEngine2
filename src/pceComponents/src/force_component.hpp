#ifndef force_component_hpp
#define force_component_hpp

#include <unordered_map>
#include <glm/vec3.hpp>

namespace pce {

struct Force
{
    double of_gravity;
    double of_contacts;
    //!< TODO: Determine exactly what the uint32_ts are below
    //!< NOTE: they could definitely be verticies of a rigid object
    std::unordered_map<uint32_t, glm::dvec3> contact_points;
    std::unordered_map<uint32_t, glm::dvec3> contact_directions;
    std::unordered_map<uint32_t, double> surfaces_of_contact_roughness;
    std::unordered_map<uint32_t, double> momentums;
    std::unordered_map<uint32_t, double> rotational_momentums;
    std::unordered_map<uint32_t, double> sequential_collisions_by_entity;
};

} /* namespace pce */
#endif /* force_component_hpp */
