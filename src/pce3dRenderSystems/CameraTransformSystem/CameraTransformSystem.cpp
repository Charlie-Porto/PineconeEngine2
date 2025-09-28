#include "CameraTransformSystem.hpp"
#include <pceMaths/quaternion_functions.hpp>
#include <pceComponents/position_component.hpp>
#include <pceComponents/rigid_object_component.hpp>
#include <pceECS/ControlPanel.hpp>

#include <pceLogger/pceLogger.hpp>

namespace {
constexpr const char* log_name = "CameraTransformSystem";
} /* namespace */

namespace pce {


CameraTransformSystem::CameraTransformSystem(ControlPanel* control)
  : ISystem(control)
{}

void CameraTransformSystem::update(const glm::dvec3& camera_position
                                 , const glm::dquat& camera_rotation)
{
    const glm::dquat opposite_cam_rotation = glm::inverse(camera_rotation);
    for (const auto& entity : entities)
    {
        auto& rigid_obj = control->GetComponent<RigidObject>(entity);
        auto& position = control->GetComponent<Position>(entity);

        const glm::dvec3 position_rel_to_cam = position.com - camera_position;
        position.cam_rel_com = rotateVector3byQuaternion(position_rel_to_cam, opposite_cam_rotation);

        //!< Update vertex positions relative to camera
        for (const auto& [id, vertex] : rigid_obj.vertices)
        {
            const glm::dvec3 v_pos_rel_to_cam = vertex - camera_position;
            rigid_obj.camera_transformed_vertices[id]
                = rotateVector3byQuaternion(v_pos_rel_to_cam,
                                            opposite_cam_rotation);
       }
       //!< Update corner (?) positions relative to camera
       //!< TODO: understand "corner" vs vertex
       //!< TODO: Try to comment this out later and see what happens. Might be redundant.
       for (const auto& [id, corner] : rigid_obj.face_corner_map) {
            const glm::dvec3 c_pos_rel_to_cam = corner - camera_position;
            rigid_obj.camera_rotated_face_corner_map[id]
                = rotateVector3byQuaternion(c_pos_rel_to_cam,
                                            opposite_cam_rotation);
       }
    }
}


} /* namespace pce */
