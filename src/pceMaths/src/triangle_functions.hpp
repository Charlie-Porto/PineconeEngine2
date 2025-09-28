#ifndef triangle_functions_hpp
#define triangle_functions_hpp

#include <cmath>
#include <utility>
#include <unordered_map>
#include <vector>

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/geometric.hpp>

namespace pce {
namespace maths {

using VertexId = uint32_t;
using FaceId = uint32_t;
using VertexMap = std::unordered_map<VertexId, glm::dvec3>;

//!< TODO: make this function just do sort the vertex list in-place
//!<       instead of returning a new one
std::vector<uint32_t> sortVerticesByDistance(const VertexMap& vertices, 
                                             const std::vector<FaceId>& face);
  
//!< TODO: determine what I meant by "sorted face"
glm::dvec3 determineCrawlDirection(const VertexMap& vertices, 
                                   const std::vector<FaceId>& sorted_face);


} /* namespace maths */
} /* namespace pce */
#endif /* triangle_functions_hpp */
