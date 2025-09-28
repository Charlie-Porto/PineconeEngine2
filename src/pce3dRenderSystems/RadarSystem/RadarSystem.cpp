#include "RadarSystem.hpp"

#include "util/radarFunctions.hpp"

#include <pceComponents/rigid_object_component.hpp>
#include <pceComponents/position_component.hpp>
#include <pceComponents/radar_component.hpp>

#include <pceECS/ControlPanel.hpp>

#include <algorithm>
#include <vector>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

#include <pceLogger/pceLogger.hpp>

//#include "DevRenderSystem.cpp"
namespace {
constexpr const char* log_name = "RadarSystem";
}


namespace pce {


RadarSystem::RadarSystem(ControlPanel* control)
  : ISystem(control)
{}


void RadarSystem::updateEntities()
{
    for (const auto& entity : entities)
    {
        auto& rigid_obj = control->GetComponent<pce::RigidObject>(entity);
        auto& pos = control->GetComponent<pce::Position>(entity);
        auto& radar = control->GetComponent<pce::Radar>(entity);

        {  //!< individual scope because I want to reuse the var name below
            const std::optional<std::pair<int, int>> potential_pixel = viewSpherePointToPixel(pos.cam_rel_com);
            if (potential_pixel != std::nullopt)
            {
                //LOG_DEBUG(log_name) << "assigning com_radar_pixel: " << potential_pixel.value().first << ", " << potential_pixel.value().second;
                pos.com_radar_pixel = 
                    glm::ivec2(potential_pixel.value().first,
                               potential_pixel.value().second);
            }
            else
            {
                pos.com_radar_pixel = std::nullopt;
            }
        } 
        //!< TODO: evaluate if distance from camera should be updated here or not
        pos.distance_from_camera = sqrt(glm::dot(pos.cam_rel_com, pos.cam_rel_com));

        radar.closest_vertex_distance = 1000000;
        radar.farthest_vertex_distance = 1;
        for (const auto& [id, vertex] : rigid_obj.camera_transformed_vertices)
        {
            const std::optional<std::pair<int, int>> potential_pixel = viewSpherePointToPixel(vertex);
            if (potential_pixel != std::nullopt)
                rigid_obj.vertex_pixels[id] = potential_pixel.value();
            rigid_obj.vertex_distance_map[id] = sqrt(glm::dot(vertex, vertex));

            if (rigid_obj.vertex_distance_map.at(id) < radar.closest_vertex_distance)
            {
                radar.closest_vertex_id = id;
                radar.closest_vertex_distance = rigid_obj.vertex_distance_map.at(id);
            }
            else if (rigid_obj.vertex_distance_map.at(id) > radar.farthest_vertex_distance)
            {
                radar.farthest_vertex_id = id;
                radar.farthest_vertex_distance = rigid_obj.vertex_distance_map.at(id);
            }
        }
    }
}

} /* namespace pce */
