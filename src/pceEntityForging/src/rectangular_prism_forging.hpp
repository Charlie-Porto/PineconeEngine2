#ifndef rectangular_prism_forging_hpp
#define rectangular_prism_forging_hpp

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
functions to forge rectangular prism entities
-----------------------------------------------------------------*/
#include "base_entity_forging.hpp"

#include <array>
#include <vector>
#include <utility>
#include <unordered_map>
#include <glm/vec3.hpp>
#include <glm/ext/quaternion_double.hpp>
#include "forge_functions.hpp"

#include <pceECS/ControlPanel.hpp>

namespace pce {
namespace forge {


struct CuboidForgingParams : public EntityForgingParams
{
    const double width = 1;
    const double height = 1;
    const double length = 1;
    const glm::dvec3 axis_of_initial_rotation = {0, 0, 1};
    const double angle_of_initial_rotation = 0.0;
};


Entity forgeRectPrismEntity(ControlPanel& control
                          , const CuboidForgingParams& cfp);


MapIdToDvec3 calculateRectPrismOriginalVertexLocations(const double w, const double h, const double l, 
                                                       const glm::dvec3& center);
                          
MapIdToIdVect assignVerticesToFaces();

MapIdToIdPair assignEdgesToVertices();

MapIdToIdVect assignVerticestoVertices();

void registerRectPrismEntityWithOrderRenderSystem(double size);


} /* namespace forge */
} /* namespace pce */




#endif /* rectangular_prism_forging_hpp */
