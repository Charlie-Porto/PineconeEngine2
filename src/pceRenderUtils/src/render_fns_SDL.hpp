#ifndef render_functions_SDL_hpp
#define render_functions_SDL_hpp


#include <array>
#include <vector>

#include <glm/vec2.hpp>


struct SDL_Renderer;


namespace pce {
namespace render {

void renderPixels( SDL_Renderer* renderer
                 , const std::vector<glm::ivec2>& pixels
                 , const std::array<uint8_t, 4>& color = {255, 255, 255, 255});

void renderLineSegments( SDL_Renderer* renderer
                       , const std::vector<std::pair<glm::ivec2, glm::ivec2>>& lines
                       , const std::array<uint8_t, 4>& color = {255, 255, 255, 255});
                    
void renderCircle( SDL_Renderer* renderer
                 , const int xc
                 , const int yc
                 , const int r
                 , const std::array<uint8_t, 4>& color = {255, 255, 255, 255}
                 , const bool fill=false);

} /* namespace render */
} /* namespace pce */


#endif /* render_functions_SDL_hpp */
