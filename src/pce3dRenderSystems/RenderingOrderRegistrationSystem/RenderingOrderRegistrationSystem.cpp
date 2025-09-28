#include "RenderingOrderRegistrationSystem.hpp"

#include <utility>
#include <vector>

#include <pceLogger/pceLogger.hpp>

#include <pceMaths/vector_functions.hpp>
#include <pceComponents/render_component.hpp>
#include <pceComponents/radar_component.hpp>
#include <pceComponents/rigid_object_component.hpp>
#include <pceComponents/order_of_render_registration_component.hpp>
#include <pceECS/ControlPanel.hpp>

struct SDL_Renderer;

namespace {
const char* log_name = "RegisterForOrderOfRenderSystem";
}

namespace pce {

RegisterForOrderOfRenderSystem::RegisterForOrderOfRenderSystem(ControlPanel* control)
 : ISystem(control)
 , order_of_ordering_({})
{}

void RegisterForOrderOfRenderSystem::registerForOrderOfRenderSystem() 
{
  for (auto const& entity : entities) 
  {
    LOG_DEBUG(log_name) << "registering entity: " << entity;
    //auto& render = control->GetComponent<Render<SDL_Renderer>>(entity); 
    auto& orender = control->GetComponent<OrderOfRenderRegistration>(entity); 
    auto const& radar = control->GetComponent<Radar>(entity); 
    auto const& rigid_object = control->GetComponent<RigidObject>(entity); 

    //!< TEMPORARY COMMENTED OUT.
    //const glm::vec3 v_closest_location = rigid_object.vertices.at(radar.closest_vertex_id);
    //const glm::vec3 v_farthest_location = rigid_object.vertices.at(radar.farthest_vertex_id);
    //const double distance = math::calculateDistanceBetweenVectors(v_closest_location, v_farthest_location);
    const double distance = static_cast<double>(entity);
    //continue;

    bool inserted = false;
    //for (size_t i = 0; i != order_of_ordering_.size(); ++i)
    //{
    //  if (distance > order_of_ordering_[i].second)
    //  {
    //    order_of_ordering_.insert(order_of_ordering_.begin() + i, std::make_pair(entity, distance));
    //    inserted = true;
    //    break;
    //  }
    //}
    if (!inserted) { order_of_ordering_.push_back(std::make_pair(entity, distance)); }
   // orender.just_registered = true;
    control->RemoveComponent<OrderOfRenderRegistration>(entity); 
  }
  entities.clear();
}

} /* namespace pce */
