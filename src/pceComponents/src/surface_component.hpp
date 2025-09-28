#ifndef surface_component_hpp
#define surface_component_hpp

#include <vector>
#include <array>
#include <unordered_map>

namespace pce {

struct Surface
{
    //std::vector<int> color;
    std::array<uint8_t, 4> color;
    using FaceId = uint32_t;
    std::unordered_map<FaceId, std::vector<int>> face_color_map;
    double opacity;
    bool is_transparent = false;
};

}

#endif /* surface_component_hpp */
