#include "cameraOperatorFunctions.hpp"
#include <pceMaths/quaternion_functions.hpp>
#include <pceMaths/sign.hpp>

#include <cmath>
#include <unordered_map>

#include <pceLogger/pceLogger.hpp>

namespace {
constexpr const char* log_name = "cameraOpFns";
}



namespace pce {


void updateCameraPosition(const VirtualKeyboard vk
                        , glm::dvec3& position
                        , const glm::dquat& rotation_versor
                        , const double speed)
{
    const std::unordered_map<Key, glm::dvec3> key_to_position_adjustment = {
        { Key::w, glm::dvec3(0, 0, 1) },
        { Key::s, glm::dvec3(0, 0, -1) },
        { Key::a, glm::dvec3(-1, 0, 0) },
        { Key::d, glm::dvec3(1, 0, 0) },
        { Key::f, glm::dvec3(0, -1, 0) },
        { Key::r, glm::dvec3(0, 1, 0) },
    };

    glm::dvec3 position_adjustment{ 0, 0, 0 };
    for (const auto& [key, movement_vec3] : key_to_position_adjustment)
        if (vk.pressed(key))
            position_adjustment += movement_vec3;
    if (position_adjustment == glm::dvec3(0, 0, 0))
        return;

    LOG_DEBUG(log_name) << "camera pos: " << position.x << ", " << position.y << ", " << position.z;
    position_adjustment = glm::normalize(position_adjustment);
    LOG_DEBUG(log_name) << "position_adjustment: " << position_adjustment.x << ", " << position_adjustment.y << ", " << position_adjustment.z;
    const glm::dvec3 rotated_position_adjustment
        = rotateVector3byQuaternion(position_adjustment, rotation_versor);
    LOG_DEBUG(log_name) << "rotated_position_adjustment: " << rotated_position_adjustment.x << ", " << rotated_position_adjustment.y << ", " << rotated_position_adjustment.z;

    position += (rotated_position_adjustment * speed);
    LOG_DEBUG(log_name) << "new camera pos: " << position.x << ", " << position.y << ", " << position.z;
}


void updateCameraRotation(const VirtualKeyboard vk
                        , glm::dquat& rotation_versor
                        , const double rotation_impedence)
{    
    const std::unordered_map<Key, glm::dquat> key_to_rotation_adjustment = {
        { Key::Up,    glm::dquat(1, 1, 0, 0) },
        { Key::Down,  glm::dquat(1, -1, 0, 0) },
        { Key::Right, glm::dquat(1, 0, -1, 0) },
        { Key::Left,  glm::dquat(1, 0, 1, 0) },
        { Key::q,     glm::dquat(1, 0, 0, 1) },
        { Key::e,     glm::dquat(1, 0, 0, -1) }
    };

    const glm::dvec3 ordinary_view{0, 0, 1};
    const glm::dvec3 dov_before = rotateVector3byQuaternion(ordinary_view, rotation_versor);
    glm::dquat rotation_adjustment{ 1, 0, 0, 0 }; //!< Identity quaternion
    for (const auto& [key, rotation_dquat] : key_to_rotation_adjustment)
    {
        if (vk.pressed(key))
        {
            LOG_DEBUG(log_name) << "key pressed: " << key_to_str.at(key);
            rotation_adjustment = rotation_adjustment * rotation_dquat;
        }
    }
    if (rotation_adjustment == glm::dquat(1, 0, 0, 0))
        return;
     
    LOG_DEBUG(log_name) << "rotation versor : " << rotation_versor.w << ", " << rotation_versor.x << ", " << rotation_versor.y << ", " << rotation_versor.z;
    LOG_DEBUG(log_name) << "camera direction : " << dov_before.x << ", " << dov_before.y << ", " << dov_before.z;
    LOG_DEBUG(log_name) << "rotation adjustment (unrotated) : " << rotation_adjustment.w << ", " << rotation_adjustment.x << ", " << rotation_adjustment.y << ", " << rotation_adjustment.z;
    rotation_adjustment = glm::normalize(rotation_adjustment) / rotation_impedence;
    if (rotation_adjustment.w != 0)
        rotation_adjustment.w = math::sign(rotation_adjustment.w);
    LOG_DEBUG(log_name) << "rotation adjustment (rotated): " << rotation_adjustment.w << ", " << rotation_adjustment.x << ", " << rotation_adjustment.y << ", " << rotation_adjustment.z;

    rotation_versor = rotation_adjustment * rotation_versor;
    const glm::dvec3 dov_after = rotateVector3byQuaternion(ordinary_view, rotation_versor);

    //LOG_DEBUG(log_name) << "camera direction(before) : " << dov_before.x << ", " << dov_before.y << ", " << dov_before.z;
    //LOG_DEBUG(log_name) << "rotation adjustment normalized: " << rotation_adjustment.w << ", " << rotation_adjustment.x << ", " << rotation_adjustment.y << ", " << rotation_adjustment.z;
    LOG_DEBUG(log_name) << "updated camera direction : " << dov_after.x << ", " << dov_after.y << ", " << dov_after.z;
}


} /* namespace pce */
