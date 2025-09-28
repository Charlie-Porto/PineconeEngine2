#ifndef glm_hash_hpp
#define glm_hash_hpp

#include <functional>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

namespace std {

template <> struct hash<glm::dvec3>;
template <> struct hash<glm::ivec3>;
template <> struct hash<glm::dvec2>;

} /* namespace std */
#endif /* glm_hash_hpp */
