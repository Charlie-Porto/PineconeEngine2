#ifndef RadarSystem_hpp
#define RadarSystem_hpp

/*----------------------------------------------------------------|
--------------------- System Description -------------------------|
determines where on the screen an entity will be rendered,
based on that entity's location in 3space relative to the camera.
-----------------------------------------------------------------*/

#include <pceECS/System.hpp>


namespace pce {


class RadarSystem : public ISystem
{
public:
    RadarSystem(ControlPanel*);
    void updateEntities();
};

} /* namespace pce */
#endif /* RadarSystem_hpp */
