#ifndef render_component_hpp
#define render_component_hpp

#include "position_component.hpp"
#include "rigid_object_component.hpp"
#include "surface_component.hpp"
#include "face_shade_component.hpp"

#include <memory>
#include <functional>


namespace pce {


struct ComponentsRelevantToRender
{
    Position    position;
    RigidObject rigid_object;
    FaceShade   shade;
    Surface     surface;
};

//#ifdef GRAPHICS_API
//#   if GRAPHICS_API == SDL2
//#include <SDL2/SDL2.h>
//using RendererT = SDL_Renderer;
//#   endif
//#else
//using RendererT = void;
//#endif


template <typename RendererT>
struct Render 
{
    //bool is_registered;
    //bool just_registered;

    //!< NOTE: plan A is to use a lambda capture to access
    //!< the vars necessary to render the entity.
    std::function<void(RendererT*, ComponentsRelevantToRender*)> render_fn = nullptr;
};

} /* namespace pce */
#endif /* render_component_hpp */
