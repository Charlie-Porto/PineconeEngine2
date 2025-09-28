#ifndef ShadeSystem_hpp
#define ShadeSystem_hpp


#include <pceECS/System.hpp>

#include <glm/vec3.hpp>
#include <glm/ext/quaternion_double.hpp>

namespace pce {


class ShadeSystem : public ISystem
{
public:
    struct LightSource
    {
        glm::dvec3 position = glm::dvec3{0, 0, 0};
        double lumens = 0;
    };

    ShadeSystem(ControlPanel*);
    void updateEntities(glm::dvec3& camera_position
                      , glm::dquat& camera_rotation
                      , const std::vector<LightSource>& light_sources = {});
};


} /* namespace pce */
#endif /* ShadeSystem_hpp */
