#ifndef orderTag_hpp
#define orderTag_hpp

#include <glm/vec3.hpp>
#include <pceComponents/rigid_object_component.hpp>
#include <pceComponents/radar_component.hpp>

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
small tag struct to add some abstraction to the render-ordering process
-----------------------------------------------------------------*/

namespace pce3d {

struct orderTag
{
    uint32_t entity;
    double closest_vertex_distance;
    glm::dvec3 closest_vertex_location;
    double farthest_vertex_distance;
    const pce::Radar& radar;
    const pce::RigidObject& rigobj;

    orderTag(const pce::Radar& _radar
           , const pce::RigidObject& _rigobj);
};

} /* pce3d */
#endif /* orderTag_hpp */
