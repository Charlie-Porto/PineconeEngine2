#ifndef rectangular_prism_forging_cpp
#define rectangular_prism_forging_cpp

#include "rectangular_prism_forging.hpp"

#include <pceComponents/position_component.hpp>
#include <pceComponents/face_shade_component.hpp>
#include <pceComponents/order_of_render_registration_component.hpp>
#include <pceComponents/radar_component.hpp>
#include <pceComponents/render_component.hpp>
#include <pceComponents/rigid_object_component.hpp>
#include <pceComponents/surface_component.hpp>
#include <pceComponents/force_component.hpp>
#include <pceComponents/motion_component.hpp>


namespace pce {
namespace forge {


Entity forgeRectPrismEntity(ControlPanel& control
                          , const CuboidForgingParams& cfp)
{
  /* create new entity's major attributes */
  MapIdToDvec3 e_vertex_map = calculateRectPrismOriginalVertexLocations(cfp.width, cfp.height, cfp.length, cfp.com);
  MapIdToIdVect e_face_vertex_map = assignVerticesToFaces();
  MapIdToIdPair e_edge_map = assignEdgesToVertices();
  MapIdToIdVect vvmap = assignVerticestoVertices();
  MapIdToDvec3 face_corner_map{};
  MapIdToIdVect face_edge_map{};
  MapIdToIdsMap face_vertex_corner_map{};
  MapIdToIdsMap vertex_face_corner_map{};

  rotateVertices(e_vertex_map, cfp.angle_of_initial_rotation, cfp.axis_of_initial_rotation, cfp.com, true);
  createFaceVertexCornerMaps(e_vertex_map, e_face_vertex_map, 
                                           face_corner_map, 
                                           face_vertex_corner_map, vertex_face_corner_map,
                                           cfp.com);
  
  createFaceEdgeMap(
    e_face_vertex_map, e_edge_map, face_edge_map);
  
  MapIdToIdVect vertex_edge_map{};
  createVertexEdgeMap(vvmap, e_edge_map, vertex_edge_map);

  /* adjust vertex points based on rotation and center of mass */
  for (auto& [id, vec3] : e_vertex_map) {
    vec3 += cfp.com;
  }
  
  /* create the new entity */
  Entity new_entity = forgeEntityBase(control, cfp);
  control.AddComponent(new_entity, RigidObject{
    .radius = 0,
    .mass = cfp.width * cfp.height * cfp.length,
    //.is_deadbod = is_livebod ? false : true,
    .is_restingbod = false,
    //.is_complex_livebod = is_livebod ? true : false,
    .vertices = e_vertex_map,
    .vertex_vertex_map = vvmap,
    .base_face_id = 1,
    .face_count = 6,
    .edges = e_edge_map,
    .face_edge_map = face_edge_map,
    .vertex_edge_map = vertex_edge_map,
    .face_vertex_map = e_face_vertex_map,
    .face_corner_map = face_corner_map,
    .face_vertex_corner_map = face_vertex_corner_map,
    .vertex_face_corner_map = vertex_face_corner_map,
    //.index_face_map = {},
    .face_index_map = {},
    .entity_face_collision_map = {},
    .entity_time_collision_map = {},
    .entity_index_collision_map = {}
  });
  control.AddComponent(new_entity, Motion{
    .speed = 0.0,
    .direction = glm::dvec3(0, 0, 0),
    //.velocity = velocity,
    //.rotational_speed = rotation_speed,
    //.rotational_axis = axis_of_rotation,
    //.duration = 0.1,
    //.previous_resting_position = cfp.com,
    //.stationary_counter = 0
  });
  //control.AddComponent(new_entity, Force{ .of_gravity = g_force });
    

  for (auto const& [vertex, face_corners] : vertex_face_corner_map) {
    std::cout << "vertex: " << vertex << '\n';
  }

  return new_entity;
}



MapIdToDvec3 calculateRectPrismOriginalVertexLocations(const double w, const double h, const double l, 
                                                    const glm::dvec3& center) {
  const double half_w = w / 2.0; 
  const double half_h = h / 2.0; 
  const double half_l = l / 2.0;

  const std::vector<double> h_halfs = {half_h, -half_h};
  const std::vector<double> w_halfs = {half_w, -half_w};
  const std::vector<double> l_halfs = {half_l, -half_l};



  MapIdToDvec3 vertex_map = {};
  uint32_t vertex_id = 1;
  for (auto const& h_half : h_halfs) {
    for (auto const& w_half : w_halfs) {
      for (auto const& l_half : l_halfs) {
        vertex_map[vertex_id] = glm::dvec3(w_half, h_half, l_half);
        ++vertex_id;
      }
    }
  }

  return vertex_map;
}



MapIdToIdVect assignVerticesToFaces() {
  /* assignment done by hand (for now) */
  MapIdToIdVect face_vertex_map = {
    {1, {1, 3, 7, 5}},
    {2, {1, 2, 4, 3}},
    {3, {6, 8, 4, 2}},
    {4, {7, 8, 6, 5}},
    {5, {7, 3, 4, 8}},
    {6, {1, 5, 6, 2}}
  };
  return face_vertex_map;
}



MapIdToIdPair assignEdgesToVertices() {
  MapIdToIdPair edge_map = {
    {1, {1, 3}},
    {2, {1, 2}},
    {3, {1, 5}}, 
    {4, {4, 2}},
    {5, {4, 3}}, 
    {6, {4, 8}},
    {7, {7, 5}},
    {8, {7, 3}},
    {9, {7, 8}},
    {10, {6, 5}}, 
    {11, {6, 8}},
    {12, {6, 2}}
  };

  return edge_map;
}



MapIdToIdVect assignVerticestoVertices() {
  MapIdToIdVect vvmap = {
    {1, {3, 2, 5}},
    {2, {1, 4, 6}},
    {3, {1, 4, 7}},
    {4, {2, 3, 8}},
    {5, {1, 7, 6}},
    {6, {2, 5, 8}},
    {7, {5, 3, 8}},
    {8, {7, 4, 6}}
    // {1, {3, 2, 5}},
    // {2, {1, 3, 6}},
    // {3, {1, 4, 7}},
    // {4, {2, 8, 7}},
    // {5, {1, 7, 6}},
    // {6, {2, 5, 8}},
    // {7, {5, 3, 8}},
    // {8, {7, 4, 6}}
  };
  return vvmap;
}


}
}






#endif /* rectangular_prism_forging_cpp */
