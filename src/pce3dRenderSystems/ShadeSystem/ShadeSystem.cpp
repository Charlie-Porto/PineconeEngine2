#include "ShadeSystem.hpp"

#include <pceComponents/rigid_object_component.hpp>
#include <pceComponents/position_component.hpp>
#include <pceComponents/face_shade_component.hpp>

#include <pceECS/ControlPanel.hpp>

namespace pce {


ShadeSystem::ShadeSystem(ControlPanel* control)
  : ISystem(control)
{}

void ShadeSystem::updateEntities(glm::dvec3& camera_position
                               , glm::dquat& camera_rotation
                               , const std::vector<LightSource>& light_sources)
{
    for (const auto& entity : entities)
    {
        const auto& rigid_obj = control->GetComponent<pce::RigidObject>(entity);
        const auto& position  = control->GetComponent<pce::Position>(entity);
        auto& face_shade      = control->GetComponent<pce::FaceShade>(entity);
    }
}


} /* namespace pce */
