#ifndef sphere_forging_cpp
#define sphere_forging_cpp

#include "sphere_forging.hpp"

#include <pceRenderUtils/render_fns_SDL.hpp>

#include <pceComponents/position_component.hpp>
#include <pceComponents/face_shade_component.hpp>
#include <pceComponents/order_of_render_registration_component.hpp>
#include <pceComponents/radar_component.hpp>
#include <pceComponents/render_component.hpp>
#include <pceComponents/rigid_object_component.hpp>
#include <pceComponents/surface_component.hpp>
#include <pceComponents/force_component.hpp>
#include <pceComponents/motion_component.hpp>

#include <pceLogger/pceLogger.hpp>


namespace pce {
namespace forge {


Entity forgeSphereEntity(ControlPanel& control
                       , const SphereForgingParams& sfp)
{
    LOG_DEBUG("sphere_forging") << "forging sphere entity";
  Entity new_entity = forgeEntityBase(control, sfp);
  control.AddComponent(new_entity, RigidObject{
    .radius=sfp.radius, 
    .mass = 4.0 * 3.14 * pow(sfp.radius, 2.0),
    .is_deadbod = false,
    .is_restingbod = false,
    .vertices={std::make_pair(1, sfp.com)},
    .face_vertex_map = {{1, {1}}},
    .base_face_id = 1,
    .face_count = 1,
    //.index_face_map = {},
    .face_index_map = {},
    .entity_face_collision_map = {},
    .entity_vertex_collision_map = {},
    .entity_index_collision_map = {},
    .entity_time_collision_map = {}
  });
  auto& render_c = control.GetComponent<Render<SDL_Renderer>>(new_entity);
  render_c.render_fn = [](SDL_Renderer* renderer, ComponentsRelevantToRender* crtr)
  {
        if (renderer == nullptr || crtr == nullptr)
            return;
        render::renderCircle(renderer,
                             crtr->position.com_radar_pixel->x,
                             crtr->position.com_radar_pixel->y,
                             crtr->rigid_object.radius * 300 / crtr->rigid_object.vertex_distance_map.at(1),
                             crtr->surface.color,
                             true);
  };

  //!< TODO: add the below when working on the physics side of things
  //control.AddComponent(new_entity, Force{ .of_gravity = gravitational_force });
  //control.AddComponent(new_entity, Motion{
  //  .speed = sqrt(glm::dot(velocity, velocity)),
  //  .direction = glm::normalize(velocity),
  //  .velocity = velocity,
  //  .rotational_speed = 0.0,
  //  .rotational_axis = glm::dvec3(0, 0, 0),
  //  .duration = 0.1,
  //  .previous_resting_position = sfp.com,
  //  .stationary_counter = 0
  //});

  return new_entity;
}

}
}





#endif /* sphere_forging_cpp */
