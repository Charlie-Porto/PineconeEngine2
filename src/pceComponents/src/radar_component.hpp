#ifndef radar_component_hpp
#define radar_component_hpp

namespace pce {
struct Radar
{
    uint32_t closest_vertex_id = 1;
    double closest_vertex_distance = 10000;
    uint32_t farthest_vertex_id = 1;
    double farthest_vertex_distance = 10;
};
} /* namespace pce */

#endif /* radar_component_hpp */
