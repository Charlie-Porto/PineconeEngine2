#pragma once

#include <pceECS/ControlPanel.hpp>
#include <array>
#include <glm/vec3.hpp>


struct SDL_Renderer;

namespace pce {

struct ComponentsRelevantToRender;

namespace forge {

struct EntityForgingParams
{
    glm::dvec3 com = {0, 0, 0}; /* center of mass */
    std::array<uint8_t, 4> color = {255, 255, 255, 255};
    std::function<void(SDL_Renderer*, ComponentsRelevantToRender*)> render_fn = nullptr;

    virtual ~EntityForgingParams();
};

uint32_t forgeEntityBase(ControlPanel& control,
                         const EntityForgingParams& efp);

} /* namespace forge */
} /* namespace pce */
