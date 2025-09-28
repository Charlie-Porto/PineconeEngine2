#include "base_entity_forging.hpp"

#include <pceComponents/position_component.hpp>
#include <pceComponents/face_shade_component.hpp>
#include <pceComponents/order_of_render_registration_component.hpp>
#include <pceComponents/order_of_render_registration_component.hpp>
#include <pceComponents/radar_component.hpp>
#include <pceComponents/render_component.hpp>
#include <pceComponents/rigid_object_component.hpp>
#include <pceComponents/surface_component.hpp>

#include <SDL2/SDL.h>

#include <pceLogger/pceLogger.hpp>

namespace{
constexpr const char* log_name = "base_entity_forging";
}

namespace pce {
namespace forge {


EntityForgingParams::~EntityForgingParams(){}


uint32_t forgeEntityBase(ControlPanel& control,
                         const EntityForgingParams& efp)
{
    LOG_DEBUG(log_name) << "forging entity base";
    const uint32_t e = control.CreateEntity();

    LOG_DEBUG(log_name) << "entity starting position: " << int(e) << ": " << int(efp.com.x) << ", " << int(efp.com.y) << ", " << int(efp.com.z);
    control.AddComponent(e, Position{.com = efp.com});
    control.AddComponent(e, Radar{});
    control.AddComponent(e, FaceShade{});
    control.AddComponent(e, Render<SDL_Renderer>{.render_fn = efp.render_fn});
    control.AddComponent(e, OrderOfRenderRegistration{});
    control.AddComponent(e, Surface{
      .color = efp.color,
    });
    //control.AddComponent(e, pce::MassDistribution{});
    return e;
}


} /* namespace forge */
} /* namespace pce */
