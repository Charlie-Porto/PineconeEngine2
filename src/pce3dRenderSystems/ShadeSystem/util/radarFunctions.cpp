#include "radarFunctions.hpp"
#include <cmath>

namespace pce {

//const double PIXEL_ANGLE = 1.0;
//const double Y_PIXEL_STRETCH = 52.0;
//const double PI = 3.14159265;
namespace {
const double RAD_PER_PIXEL = 0.0087; //!< 0.5 degrees
} /* namespace */

std::optional<std::pair<int, int>> viewSpherePointToPixel(const glm::dvec3& point)
{
    //!< Check if point is behind camera  
    if (point.z < 1 /* experiment with this value to get it right */)
        return std::nullopt;
    
    const double xz_rad = atan( point.x / point.z );
    const double yz_rad = atan( point.y / point.z );
    const double eighty_deg_rad = 1.39;
    if (abs(xz_rad) > eighty_deg_rad || abs(yz_rad) > eighty_deg_rad)
        return std::nullopt;
    
    return std::make_pair(
        static_cast<int>( yz_rad / RAD_PER_PIXEL ),
        static_cast<int>( xz_rad / RAD_PER_PIXEL )
    );
}

glm::dvec3 pixelToViewSpherePoint(std::pair<int, int>& pixel)
{
    //!< TODO: implement this (only needed for dev render system iirc)
}

//glm::dvec2 convertPointOnViewSphereToPixel(const glm::dvec3& point, bool is_center_of_gravity, bool is_first_pass) {
//  glm::dvec3 mpoint = point;
//  bool to_interpolate = false;
//  if (!is_first_pass) {
//    if (point.z < -0.2) {
//      if (is_center_of_gravity) 
//      {
//        return glm::dvec2(0, 0); 
//      }
//      // to_interpolate = true;
//    }
//    if (abs(atan(point.x/point.z) / PI * 180.0) > 70.0) {
//      if (is_center_of_gravity) 
//      {
//        return glm::dvec2(0, 0); 
//      }
//      // to_interpolate = true;
//    }
//    if (abs(atan(point.y/point.z) / PI * 180.0) > 50.0) {
//      if (is_center_of_gravity) 
//      {
//        return glm::dvec2(0, 0); 
//      }
//      // to_interpolate = true;
//    }
//    // if (to_interpolate)
//    // {
//    //   mpoint = interpolateViewSphereIntersectionPoint(point, 1, glm::dvec3(0, 10.0, 10.0));
//    // }
//  }
//  const double y_pixel = Y_PIXEL_STRETCH * atan(mpoint.y / mpoint.z);
//  const double x_pixel = atan(mpoint.x / mpoint.z) / (PIXEL_ANGLE * PI / 180.0);
//  return glm::dvec2(x_pixel, y_pixel) * pce::math::sign(mpoint.z);
//}
//
//
//glm::dvec3 convertPixelToPointOnViewSphere(const glm::dvec2& pixel) {
//  const double z = 1.0 / (1.0 + tan(double(pixel.y) / Y_PIXEL_STRETCH) - tan(double(pixel.x) * (PIXEL_ANGLE * PI / 180.0)));
//  const double x = z * tan(pixel.x * (PIXEL_ANGLE * PI / 180.0));
//  const double y = z * tan(pixel.y / Y_PIXEL_STRETCH);
//  // std::cout << "viewsphere point: " << x << ", " << y << ", " << z << "\n";
//  return glm::dvec3(x, y, z);
//}
//
//
//
//glm::dvec3 interpolateViewSphereIntersectionPoint(const glm::dvec3& point, const double z_target,
//                                                  const glm::dvec3& connected_on_screen_point) {
//  std::cout << "interpolating!!!!!!!!" << '\n';
//  // const glm::dvec3 direction = glm::normalize(point - connected_on_screen_point);
//  // const glm::dvec3 point_on_line = connected_on_screen_point + direction;
//  // return -point_on_line;
//
//  // if (point.z == connected_on_screen_point.z && point.y == connected_on_screen_point.y) {
//  //   return (glm::normalize(glm::dvec3(point.x, connected_on_screen_point.y, z_target)));
//  // }
//  // if (point.z == connected_on_screen_point.z && point.x == connected_on_screen_point.x) {
//  //   return (glm::normalize(glm::dvec3(connected_on_screen_point.x, point.y, z_target)));
//  // }
//
//  const glm::dvec3 direction = glm::normalize(point - connected_on_screen_point);
//  std::cout << "direction: "
//            << direction.x << ", "
//            << direction.y << ", "
//            << direction.z << '\n';
//  std::cout << "point: "<<point.x << ", "<< point.y << ", "<< point.z << '\n';
//  std::cout << "screenpoint: "
//            << connected_on_screen_point.x << ", "
//            << connected_on_screen_point.y << ", "
//            << connected_on_screen_point.z << '\n';
//
//  double t = (z_target - connected_on_screen_point.z) / direction.z;
//  // glm::dvec3 psuedo_intersection_point = glm::dvec3(abs(point.x + t * direction.x) * pce::math::sign(point.x), abs(point.y + t * direction.y) * pce::math::sign(point.y), z_target);
//  glm::dvec3 psuedo_intersection_point = glm::dvec3(point.x + t * direction.x, point.y + t * direction.y, z_target);
//  // glm::dvec3 psuedo_intersection_point = glm::dvec3(abs(connected_on_screen_point.x + t * direction.x) * pce::math::sign(point.x), 
//                                                    // abs(connected_on_screen_point.y + t * direction.y) * pce::math::sign(point.y), 
//                                                    // z_target);
//  glm::dvec3 unit_psuedo_int_point = glm::normalize(psuedo_intersection_point);
//  std::cout << "unit_psuedo_int_point: "
//            << unit_psuedo_int_point.x << ", "
//            << unit_psuedo_int_point.y << ", "
//            << unit_psuedo_int_point.z << '\n';
//
//  return unit_psuedo_int_point;
//
//}


} /* namespace pce */
