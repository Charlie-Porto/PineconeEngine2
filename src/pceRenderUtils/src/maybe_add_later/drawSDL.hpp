#ifndef quickdraw_hpp
#define quickdraw_hpp

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
functions to render simple objects easily 
-----------------------------------------------------------------*/


#include <vector>
#include <glm/vec2.hpp>

#include <SDL2/SDL.h>

#include "SDL_cartesian_conversion.hpp"
//#include "render_functions.hpp"
//#include "raster_functions.hpp"
//#include "triangle_raster_functions.hpp"

//#include "pceMaths/Triangle.hpp"
//#include "pceMaths/Quadrilateral.hpp"

/* include primary .hpp file for access to global vars */
//#include "../../pce3d.hpp"

namespace pce {
namespace drawSDL {

void drawCircle( const SDL_Renderer* renderer
               , const glm::vec2& center_pixel
               , const int rad_pixels 
               , const std::array<uint8_t, 4>& color
               , const bool filled=false);
    

//void drawSetOfEdges(const std::vector<std::pair<glm::dvec2, glm::dvec2>>& edges, 
//                    const std::vector<int>& color);
//   
//void drawFilledRect(const glm::dvec2& top_L_corner, const glm::dvec2& lower_R_corner, 
//                    const std::vector<int>& color);
//
//void drawFilledQuadrilateral(const pce3d::maths::Quadrilateral& quadrilateral,
//                             const std::vector<int>& color);
//
//void drawFilledTriangle(const pce3d::maths::Triangle& triangle,
//                        const std::vector<int>& color);
//
}
}







#endif /* quickdraw_hpp */
