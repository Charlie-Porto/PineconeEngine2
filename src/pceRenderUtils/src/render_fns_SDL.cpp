#include "render_fns_SDL.hpp"
#include "raster_functions.hpp"
#include "SDL_cartesian_conversion.hpp"

#include <SDL2/SDL.h> //!< for renderer

#include <pceLogger/pceLogger.hpp>
namespace {
constexpr const char* log_name = "render_fns";
} /* namespace */


namespace pce {
using namespace raster;
namespace render {

//!< Expects Cartesian
void renderPixels( SDL_Renderer* renderer
                 , const std::vector<glm::ivec2>& pixels
                 , const std::array<uint8_t, 4>& color)
{
    if (renderer == nullptr)
        return;
    SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
    for (const auto& p : pixels)
    {
        const glm::ivec2 p_sdl = convert::cartesianToSDL(p);
        SDL_RenderDrawPoint(renderer, p_sdl.x, p_sdl.y);
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}


//!< Expects cartesian
void renderLineSegments( SDL_Renderer* renderer
                       , const std::vector<std::pair<glm::ivec2, glm::ivec2>>& lines
                       , const std::array<uint8_t, 4>& color)
{
    if (renderer == nullptr)
        return;
      
    SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
    for (const auto& point : lines)
    {
        const glm::ivec2 p1_sdl = convert::cartesianToSDL(point.first);
        const glm::ivec2 p2_sdl = convert::cartesianToSDL(point.second);
        SDL_RenderDrawLine(renderer, p1_sdl.x, p1_sdl.y, p2_sdl.x, p2_sdl.y);
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}
                    

void renderCircle( SDL_Renderer* renderer
                 , const int xc
                 , const int yc
                 , const int r
                 , const std::array<uint8_t, 4>& color
                 , const bool fill)
{
    if (renderer == nullptr)
        return;
    if (!fill)
    {
        const std::vector<glm::ivec2> pixels = rasterizeCircle(xc, yc, r);
        renderPixels(renderer, pixels, color);
        return;
    }

    //!< Draw filled-in circle
    const std::vector<std::pair<glm::ivec2, glm::ivec2>> point_pairs 
        = rasterizeCircleHorizontalPointsPaired(xc, yc, r);
    renderLineSegments(renderer, point_pairs, color); 
}

} /* namespace render */
} /* namespace pce */
