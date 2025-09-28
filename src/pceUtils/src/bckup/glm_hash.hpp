//#ifndef glm_hash_hpp
//#define glm_hash_hpp

#pragma once

#include <functional>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

template <>
struct std::hash<glm::dvec3>
{
    size_t operator()( const glm::dvec3& v ) const;
};

template <>
struct std::hash<glm::ivec3>
{
    size_t operator()( const glm::ivec3& v ) const;
};

template <>
struct std::hash<glm::dvec2> 
{
    size_t operator()( const glm::dvec2& v ) const;
};


//#endif /* glm_hash_hpp */
