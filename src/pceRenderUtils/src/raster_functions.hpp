#ifndef raster_functions_hpp
#define raster_functions_hpp

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
functions to rasterize shapes of certain types
-----------------------------------------------------------------*/

#include <vector>

#include <glm/vec2.hpp>



namespace pce {
namespace raster {


std::vector<glm::ivec2> rasterizeCircle(int xc, int yc, int r);

std::vector<std::pair<glm::ivec2, glm::ivec2>> rasterizeCircleHorizontalPointsPaired(int xc, int yc, int r);

//std::vector<glm::ivec2> getEllipseRasterPoints(
//    const glm::dvec2& center
//  , const glm::dvec2& a_focus
//  , const glm::dvec2& b_focus
//  , const double semi_major_axis
//  , const int num_sides
//);

  
}
}




#endif /* raster_functions_hpp */
