#ifndef face_shade_component_hpp
#define face_shade_component_hpp

#include <unordered_map>
//#include <pceUtils/glm_hash.hpp>

namespace pce {

using FaceId = uint32_t;
using FaceShadeMap = std::unordered_map<FaceId, double>;
//using PixelShadeMap = std::unordered_map<glm::dvec2, double, KelpHasher<glm::dvec2>>;
//using PixelMap = std::unordered_map<glm::dvec2, glm::dvec2, KelpHasher<glm::dvec2>>;
//using SurfaceZoneBrightnessMap = std::unordered_map<glm::dvec3, double, KelpHasher<glm::dvec3>>;

struct FaceShade
{
    FaceShadeMap face_shade_map;
    double virtual_pixel_ratio = 1.0;
    //PixelShadeMap pixel_shade_map;
    //PixelMap outline_pixels{};
    double center_point_shade;
    //SurfaceZoneBrightnessMap surface_zone_brightness_map;
    //SurfaceZoneBrightnessMap camera_transformed_surface_zone_brightness_map;
};

} /* namespace pce */
#endif /* face_shade_component_hpp */
