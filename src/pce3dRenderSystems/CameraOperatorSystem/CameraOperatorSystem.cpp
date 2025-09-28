#include "CameraOperatorSystem.hpp"
#include <pceCamera/cameraOperatorFunctions.hpp>


namespace pce {


void CameraOperatorSystem::update(Camera& camera, VirtualKeyboard vk)
{
    updateCameraPosition(
        vk,
        camera.position,
        camera.rotation_versor,
        camera.speed
    );
    updateCameraRotation(
        vk,
        camera.rotation_versor,
        camera.rotation_impedence
    );
}


} /* namespace pce */
