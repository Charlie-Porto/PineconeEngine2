#ifndef cameraOperatorFunctions_hpp
#define cameraOperatorFunctions_hpp

#include <glm/ext/quaternion_double.hpp>
#include <glm/vec3.hpp>
#include <pceUtils/virtual_keyboard.hpp>


namespace pce {

void updateCameraPosition(const VirtualKeyboard vk
                        , glm::dvec3& position
                        , const glm::dquat& rotation_versor
                        , const double speed);

void updateCameraRotation(const VirtualKeyboard vk
                        , glm::dquat& rotation_versor
                        , const double rotation_impedence);


} /* namespace pce */
#endif /* cameraOperatorFunctions_hpp */
