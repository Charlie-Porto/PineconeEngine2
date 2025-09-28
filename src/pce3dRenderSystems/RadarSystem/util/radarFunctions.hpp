#ifndef radarFunctions_hpp
#define radarFunctions_hpp

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <glm/geometric.hpp>
#include <pceMaths/sign.hpp>

#include <utility>
#include <optional>

namespace pce {


std::optional<std::pair<int, int>> viewSpherePointToPixel(const glm::dvec3& point);
glm::dvec3 pixelToViewSpherePoint(std::pair<int, int>& pixel);

//glm::dvec3 convertPixelToPointOnViewSphere(const glm::dvec2& pixel);
//
//
//glm::dvec3 interpolateViewSphereIntersectionPoint(const glm::dvec3& point, const double z_target,
//                                                  const glm::dvec3& connected_on_screen_point);
//

} /* namespace pce */
#endif /* radarFunctions_hpp */
