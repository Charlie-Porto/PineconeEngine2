#ifndef surface_component_hpp
#define surface_component_hpp

#include <vector>
#include <array>
#include <unordered_map>

namespace pce {

struct Surface
{
    std::array<uint8_t, 4> color;
    using FaceId = uint32_t;
    std::unordered_map<FaceId, std::array<uint8_t, 4>> face_color_map;
    double opacity;
};

}

#endif /* surface_component_hpp */
