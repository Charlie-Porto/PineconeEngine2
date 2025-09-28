#include "RenderPipeline.hpp"

#include <functional>
//#include <pceUtils/glm_hash.hpp>
#include <pceComponents/position_component.hpp>
#include <pceComponents/face_shade_component.hpp>
#include <pceComponents/order_of_render_registration_component.hpp>
#include <pceComponents/radar_component.hpp>
#include <pceComponents/render_component.hpp>
#include <pceComponents/rigid_object_component.hpp>
#include <pceComponents/surface_component.hpp>

#include <pceLogger/pceLogger.hpp>

//#include <SDL2/SDL.h>

namespace 
{
constexpr const char* log_name = "RenderPipeline";
}


namespace pce {
    

RenderPipelineSDL::RenderPipelineSDL(ControlPanel& control,
                                     SDL_Renderer* renderer)
  : control_(control)
  , co_sys_(std::make_shared<CameraOperatorSystem>())           //!< ready
  , ct_sys_(control.RegisterSystem<CameraTransformSystem>())    //!< ready
  , ror_sys_(control.RegisterSystem<RegisterForOrderOfRenderSystem>()) //!< MAYBE ready
  , ofr_sys_(control.RegisterSystem<OrderForRenderSystem>())    //!< ready
  , rad_sys_(control.RegisterSystem<RadarSystem>())             //!< ready
  , sh_sys_(control.RegisterSystem<ShadeSystem>())              //!< NOT ready
  , ren_sys_(control.RegisterSystem<RenderSystem<SDL_Renderer>>()) //!< NOT ready. TODO: make ready for balls
{
    LOG_DEBUG(log_name) << "RenderPiplineSDL: ctor";
    control_.RegisterComponent<RigidObject>();
    control.RegisterComponent<pce::Position>();
    control.RegisterComponent<Surface>();
    control.RegisterComponent<Radar>();
    control.RegisterComponent<pce::Render<SDL_Renderer>>();
    control.RegisterComponent<FaceShade>();
    control.RegisterComponent<OrderOfRenderRegistration>();

    ren_sys_->setRenderer(renderer); 
}

void RenderPipelineSDL::update(const std::vector<SDL_Event>& frame_events)
{
    //LOG_DEBUG(log_name) << "updating...";
    virtual_keyboard_.updateStatusSDL(frame_events);
    co_sys_->update(camera_, virtual_keyboard_);
    ct_sys_->update(camera_.position, camera_.rotation_versor);
    ror_sys_->registerForOrderOfRenderSystem();
    ofr_sys_->updateEntities(ror_sys_->order_of_ordering_);
    rad_sys_->updateEntities();
    ren_sys_->updateEntities(ofr_sys_->order_list_);
}


} /* namespace pce */
