#ifndef CameraTransformSystem_hpp
#define CameraTransformSystem_hpp

#include <pceECS/System.hpp>

#include <pceCamera/camera.hpp>

#include <glm/vec3.hpp>
#include <glm/ext/quaternion_double.hpp>


namespace pce {

class CameraTransformSystem : public ISystem
{
public:
    CameraTransformSystem(ControlPanel*);
    void update(const glm::dvec3& camera_position
              , const glm::dquat& camera_rotation);
};


} /* namespace pce */
#endif /* CameraTransformSystem_hpp */
