#include "glm_hash.hpp"


size_t std::hash<glm::dvec3>::operator()( const glm::dvec3& v ) const
{
    std::size_t res = 17;
    res = res * 31 + std::hash<double>{}( v.x );
    res = res * 31 + std::hash<double>{}( v.y );
    res = res * 31 + std::hash<double>{}( v.z );

    return res;
}


size_t std::hash<glm::ivec3>::operator()( const glm::ivec3& v ) const
{
    std::size_t res = 17;
    res = res * 31 + std::hash<int>{}( v.x );
    res = res * 31 + std::hash<int>{}( v.y );
    res = res * 31 + std::hash<int>{}( v.z );

    return res;
}


size_t std::hash<glm::dvec2>::operator()( const glm::dvec2& v ) const
{
    std::size_t resa = 31 + std::hash<double>{}( v.x );
    std::size_t resb = 31 + std::hash<double>{}( v.y );

    return resa ^ (resb << 1);
}
