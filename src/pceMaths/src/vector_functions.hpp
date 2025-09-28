#ifndef vector_functions_hpp
#define vector_functions_hpp

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
functions for vectors
-----------------------------------------------------------------*/

#include <utility>
#include <cmath>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/geometric.hpp>
#include "pce_psuedo_randomness.hpp"

namespace pce {
namespace math {

template <typename T> double calculateDistanceBetweenVectors(const T& A, const T& B);

template <typename T> double calculateAngleDegreesBetweenVectors(const T& A, const T& B);

double calcMagV3(const glm::dvec3& A);

double calcMagV2(const glm::dvec2& A);

bool determineIfVec3MakesLineWithTwoVec3s(const glm::dvec3& A, const glm::dvec3& B, const glm::dvec3& C);

glm::dvec3 findClosestPointOnVec3LineToVec3(const glm::dvec3& A, const glm::dvec3& B, const glm::dvec3& C);

double calculateDistanceBetweenPointAndLine(const glm::dvec3& A, const glm::dvec3& B, const glm::dvec3& C);

bool determineIfLineVectorsWithinDistanceAndAtWhichPoint(
  const glm::dvec3& A, const glm::dvec3& B, 
  const glm::dvec3& C, const glm::dvec3& D,
  const double distance_threshold
);

std::pair<double, glm::dvec3> estimateDistanceAndMidPointOfClosestPointsOnLines(
  const glm::dvec3& A, const glm::dvec3& B, 
  const glm::dvec3& C, const glm::dvec3& D
);


//!< fn template definitions
template <typename T> double calculateDistanceBetweenVectors(const T& A, const T& B) {
    return sqrt(glm::dot(A-B, A-B));
}
template <typename T> double calculateAngleDegreesBetweenVectors(const T& A, const T& B) {
    return acos( glm::dot(A, B) / (sqrt(glm::dot(A, A)) * sqrt(glm::dot(B, B)))) / 3.14159265 * 180.0;
}

}
}





#endif /* vector_functions_hpp */
