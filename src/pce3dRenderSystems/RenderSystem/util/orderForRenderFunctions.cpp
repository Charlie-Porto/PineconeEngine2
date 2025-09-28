#include "orderForRenderFunctions.hpp"

namespace pce3d {
namespace render_order {
using namespace pce;


namespace {

uint32_t determineBiggerForCloserOfTwoCalc(const std::shared_ptr<orderTag> a_entity_tag,
                                           const std::shared_ptr<orderTag> b_entity_tag)
{
    //!< simple calculation if two spheres
    if (a_entity_tag->rigobj.vertices.size() == 1 && b_entity_tag->rigobj.vertices.size() == 1)
    {
        return a_entity_tag->closest_vertex_distance <= b_entity_tag->closest_vertex_distance
          ? a_entity_tag->entity : b_entity_tag->entity;
    }

    //!< the "bigger" entity:
    //!< 1) has the farther closest vertex
    //!< 2) is not be a sphere if the small entity is not
    if (b_entity_tag->rigobj.radius > 0)
        return a_entity_tag->entity;
    if (b_entity_tag->closest_vertex_distance < a_entity_tag->closest_vertex_distance)
        return a_entity_tag->entity;
    //!< Also want big entity to
    //!< 3) Be bigger, according to this calc:
    if (pce3d::maths::calculateDistanceBetweenVectors(a_entity_tag->rigobj.vertices.at(a_entity_tag->radar.closest_vertex_id),
                                                      a_entity_tag->rigobj.vertices.at(a_entity_tag->radar.farthest_vertex_id))
     > pce3d::maths::calculateDistanceBetweenVectors(b_entity_tag->rigobj.vertices.at(b_entity_tag->radar.closest_vertex_id),
                                                     b_entity_tag->rigobj.vertices.at(b_entity_tag->radar.farthest_vertex_id)))
    {
        return a_entity_tag->entity;
    }

    return b_entity_tag->entity;
}

} /* namespace */



//!< NEED:
//!<    - rigid_object
//!<        - radius
//!<        - vertices
//!<    - radar
//!<        - closest_vertex_id
//!<        - farthest_vertex_id
uint32_t getCloserOfTwoOverlappingEntitiesToOrigin(const std::shared_ptr<orderTag> a_entity_tag,
                                                   const std::shared_ptr<orderTag> b_entity_tag)
{
    uint32_t big_entity = b_entity_tag->entity;
    uint32_t small_entity = a_entity_tag->entity;
    std::shared_ptr<orderTag> sm_entity_tag = a_entity_tag;
    std::shared_ptr<orderTag> big_entity_tag = b_entity_tag;

    bool swap = false;
    double big_radius = b_entity_tag->rigobj.radius;
    //!< If both entities are spheres, the calc is simple
    if (a_entity_tag->rigobj.vertices.size() == 1 && b_entity_tag->rigobj.vertices.size() == 1)
    {
        return a_entity_tag->closest_vertex_distance <= b_entity_tag->closest_vertex_distance
          ? a_entity_tag->entity : b_entity_tag->entity;
    }

    //!< Want big entity (in proceeding calc) to
    //!< 1) have the farther closest vertex
    //!< 2) not be a sphere if the small entity is not
    if (big_entity_tag->closest_vertex_distance < sm_entity_tag->closest_vertex_distance
     || big_radius > 0)
    {
        swap = true;
    }
    //!< Also want big entity to
    //!< 3) Be bigger, according to this calc:
    if (pce3d::maths::calculateDistanceBetweenVectors(a_entity_tag->rigobj.vertices.at(a_entity_tag->radar.closest_vertex_id), a_entity_tag->rigobj.vertices.at(a_entity_tag->radar.farthest_vertex_id))
    >  pce3d::maths::calculateDistanceBetweenVectors(b_entity_tag->rigobj.vertices.at(b_entity_tag->radar.closest_vertex_id), b_entity_tag->rigobj.vertices.at(b_entity_tag->radar.farthest_vertex_id)))
    {
        swap = true;
    }

    if (swap) 
    {
        big_entity = a_entity_tag->entity;
        small_entity = b_entity_tag->entity;
        sm_entity_tag = b_entity_tag;
        big_entity_tag = a_entity_tag;
    }

    uint32_t big_closest_face = 1;
    double big_closest_face_corner_distance = 10000;

    for (auto const& [face, corner] : big_entity_tag->rigobj.vertex_face_corner_map.at(big_entity_tag->radar.closest_vertex_id)) 
    {
        const double distance = pce3d::maths::calculateDistanceBetweenVectors(
            big_entity_tag->rigobj.camera_rotated_face_corner_map.at(corner), sm_entity_tag->closest_vertex_location);
        //dev_render_system.AddPointToPointColorMap(big_entity_tag->rigobj.camera_rotated_face_corner_map.at(corner), {130, 40, 50, 255}, 1.0);

        if (distance < big_closest_face_corner_distance) 
        {
          big_closest_face_corner_distance = distance;
          big_closest_face = face;
        }
    }


    const glm::dvec3 big_entity_face_plane_point = pce3d::maths::calculateClosestPointInPlaneToPoint(
    big_entity_tag->rigobj.camera_transformed_vertices.at(big_entity_tag->rigobj.face_vertex_map.at(big_closest_face)[0]),
    big_entity_tag->rigobj.camera_transformed_vertices.at(big_entity_tag->rigobj.face_vertex_map.at(big_closest_face)[1]),
    big_entity_tag->rigobj.camera_transformed_vertices.at(big_entity_tag->rigobj.face_vertex_map.at(big_closest_face)[2]),
    sm_entity_tag->rigobj.camera_transformed_vertices.at(sm_entity_tag->radar.closest_vertex_id)
    );

    const double big_face_point_magnitude = sqrt(glm::dot(big_entity_face_plane_point, big_entity_face_plane_point));

    //dev_render_system.AddPointToPointColorMap(big_entity_tag->closest_vertex_location, {200, 100, 200, 255}, 10.0);
    //dev_render_system.AddPointToPointColorMap(sm_entity_tag->closest_vertex_location, {20, 100, 200, 255}, 10.0);
    //dev_render_system.AddPointToPointColorMap(big_entity_face_plane_point, {30, 200, 100, 255}, 10.0);

    return big_face_point_magnitude > sm_entity_tag->closest_vertex_distance
    ? small_entity : big_entity;
}

uint32_t getCloserOfTwoEntitiesToOrigin(const std::shared_ptr<orderTag> a_entity_tag,
                                        const std::shared_ptr<orderTag> b_entity_tag)
{
  if (a_entity_tag->closest_vertex_distance <= b_entity_tag->closest_vertex_distance
   && a_entity_tag->farthest_vertex_distance <= b_entity_tag->closest_vertex_distance)
  {
    return a_entity_tag->entity;
  }
  if (a_entity_tag->closest_vertex_distance >= b_entity_tag->farthest_vertex_distance
   && a_entity_tag->farthest_vertex_distance >= b_entity_tag->farthest_vertex_distance)
  {
    return b_entity_tag->entity;
  }
  if (a_entity_tag->closest_vertex_distance == a_entity_tag->farthest_vertex_distance
   && b_entity_tag->closest_vertex_distance == b_entity_tag->farthest_vertex_distance)
  {
    return a_entity_tag->closest_vertex_distance <= b_entity_tag->closest_vertex_distance
      ? a_entity_tag->entity : b_entity_tag->entity;
  }
  else
  {
    // std::cout << "getting closer of two overlapping" << '\n';
    // std::cout << "entity a: " << a_entity_tag->entity << " | " << "entity b: " << b_entity_tag->entity << '\n';
    return getCloserOfTwoOverlappingEntitiesToOrigin(a_entity_tag, b_entity_tag);
  }
}

void insertEntityIntoOrderMapBinary(const std::shared_ptr<orderTag> entity_tag,
                                    std::vector<std::shared_ptr<orderTag>>& order_list)
{
  size_t left = 0;
  size_t right = order_list.size();
  size_t index = 0;
  size_t previous_left_right_difference = 0;

  while (left < right) 
  {
    // std::cout << "right: " << right << '\n';
    // std::cout << "left: " << left << '\n';
    size_t mid = (left + right) / 2; 
    if (right - left == previous_left_right_difference)
    {
      // index = 1;
      // std::cout << "breaking due to incoming endless loop" << '\n';
      // break;
      --right;
    }
    previous_left_right_difference = right - left;

    uint32_t closer_left_neighbor_or_entity = getCloserOfTwoEntitiesToOrigin(entity_tag, order_list[mid]);
    uint32_t closer_right_neighbor_or_entity = entity_tag->entity; 

    if (order_list.size() > 1 && mid < order_list.size()-1) 
    { 
      closer_right_neighbor_or_entity = getCloserOfTwoEntitiesToOrigin(entity_tag, order_list[mid+1]);
    }

    // std::cout << "closer left: " <<  closer_left_neighbor_or_entity<< '\n';
    // std::cout << "closer right: " <<  closer_right_neighbor_or_entity<< '\n';

    const bool this_entity_closer_than_left  
        = (closer_left_neighbor_or_entity == entity_tag->entity) ? true : false;
    const bool this_entity_closer_than_right  
        = (closer_right_neighbor_or_entity == entity_tag->entity) ? true : false;

    if (this_entity_closer_than_left && !this_entity_closer_than_right)
    {
      // std::cout << "spot found: " << '\n';
      index = mid+1;
      break;
    }
    if (this_entity_closer_than_left && this_entity_closer_than_right
       && mid == order_list.size()-1)
    {
      // std::cout << "spot found: " << '\n';
      index = mid+1;
      break;
    }
    else if (!this_entity_closer_than_left)
    {
      right = mid;
      // std::cout << "new right: " << right << '\n';
      index = mid;
    }
    else if (this_entity_closer_than_right)
    {
      left = mid; 
      // std::cout << "new left: " << left << '\n';
      index = mid;
      index = mid;
    }
  }
  // std::cout << "inserting entity:  " << entity_tag->entity << "at index: "<< index <<'\n';
  if (order_list.size() < 2 && index != 0) { order_list.push_back(entity_tag); }
  else if (order_list.size() > 2 && index >= order_list.size()) 
  {
    order_list.push_back(entity_tag);
  }
  else 
  {
    order_list.insert(order_list.begin() + index, entity_tag);
  }
}


void insertEntityIntoOrderMapStartingAtEnd(const std::shared_ptr<orderTag> entity_tag,
                                           std::vector<std::shared_ptr<orderTag>>& order_list)
{
  size_t index = order_list.size()-1;
  for (size_t i = order_list.size(); i != -1; --i)
  {
    if (order_list[i]->closest_vertex_distance == order_list[i]->farthest_vertex_distance
     && entity_tag->closest_vertex_distance == entity_tag->farthest_vertex_distance)
    {
      if (order_list[i]->closest_vertex_distance < entity_tag->closest_vertex_distance)
      {
        continue;
      }
      else
      {
        index = i;
        break;
      }
    }
    uint32_t closer_entity = getCloserOfTwoEntitiesToOrigin(entity_tag, order_list[i]);
    if (closer_entity == entity_tag->entity)
    {
      index = i;
      break;
    }
  }
  if (index == order_list.size()-1)
  {
    order_list.push_back(entity_tag);
  }
  else
  {
    order_list.insert(order_list.begin() + index, entity_tag);
  }
}
                                

}
}
