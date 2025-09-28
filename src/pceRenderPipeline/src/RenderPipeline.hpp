#pragma once

#include <memory>

#include <SDL2/SDL.h>

#include <pceLogger/pceLogger.hpp>

#include <pce3dRenderSystems/CameraOperatorSystem.hpp>
#include <pce3dRenderSystems/CameraTransformSystem.hpp>
#include <pce3dRenderSystems/OrderForRenderSystem.hpp>
#include <pce3dRenderSystems/RadarSystem.hpp>
#include <pce3dRenderSystems/RenderSystem.hpp>
#include <pce3dRenderSystems/ShadeSystem.hpp>
#include <pce3dRenderSystems/RenderingOrderRegistrationSystem.hpp>


//struct SDL_Renderer;
//struct SDL_Event;

namespace pce {


class RenderPipelineSDL
{
    ControlPanel& control_;

    Camera camera_; 
    VirtualKeyboard virtual_keyboard_; //!< TMP; should probably go elsewhere eventually.

    std::shared_ptr<CameraOperatorSystem>  co_sys_;
    std::shared_ptr<CameraTransformSystem> ct_sys_;
    std::shared_ptr<RegisterForOrderOfRenderSystem>  ror_sys_;
    std::shared_ptr<OrderForRenderSystem>  ofr_sys_;
    std::shared_ptr<RadarSystem>           rad_sys_;
    std::shared_ptr<ShadeSystem>           sh_sys_;
    std::shared_ptr<RenderSystem<SDL_Renderer>> ren_sys_;

public:
    RenderPipelineSDL(ControlPanel&,
                      SDL_Renderer*);
    void update(const std::vector<SDL_Event>& frame_events);
};


} /* namespace pce */
