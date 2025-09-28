#ifndef sphere_forging_hpp
#define sphere_forging_hpp

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
functions for creating sphere entities
-----------------------------------------------------------------*/
#include "base_entity_forging.hpp"

#include <array>
#include <utility>
#include <unordered_map>

#include <glm/vec3.hpp>
#include <glm/ext/quaternion_double.hpp>

#include <pceECS/ControlPanel.hpp>



namespace pce {
namespace forge {


struct SphereForgingParams : public EntityForgingParams
{
    double radius = 1;
};


Entity forgeSphereEntity(ControlPanel& control
                       , const SphereForgingParams& sfp);

void registerSphereEntityWithOrderRenderSystem(double size);

} /* namespace forge */
} /* namespace pce */




#endif /* sphere_forging_hpp */
