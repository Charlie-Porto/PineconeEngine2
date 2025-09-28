#include "glm_hash.hpp"

namespace std {

template <>
struct hash<glm::dvec3>
{
    size_t operator()( const glm::dvec3& v ) const;
};

template <>
struct hash<glm::ivec3>
{
    size_t operator()( const glm::ivec3& v ) const;
};

template <>
struct hash<glm::dvec2> 
{
    size_t operator()( const glm::dvec2& v ) const;
};

size_t hash<glm::dvec3>::operator()( const glm::dvec3& v ) const
{
    size_t res = 17;
    res = res * 31 + hash<double>{}( v.x );
    res = res * 31 + hash<double>{}( v.y );
    res = res * 31 + hash<double>{}( v.z );

    return res;
}


size_t hash<glm::ivec3>::operator()( const glm::ivec3& v ) const
{
    size_t res = 17;
    res = res * 31 + hash<int>{}( v.x );
    res = res * 31 + hash<int>{}( v.y );
    res = res * 31 + hash<int>{}( v.z );

    return res;
}

size_t hash<glm::dvec2>::operator()( const glm::dvec2& v ) const
{
    size_t resa = 31 + hash<double>{}( v.x );
    size_t resb = 31 + hash<double>{}( v.y );

    return resa ^ (resb << 1);
}

} /* namespace std */
