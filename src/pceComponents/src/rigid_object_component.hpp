#ifndef rigid_object_component_hpp
#define rigid_object_component_hpp

#include <unordered_map>
#include <utility>
#include <vector>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
//#include <pceUtils/glm_hash.hpp>


//template <>
//struct std::hash<glm::ivec3>
//{
//    size_t operator()( const glm::ivec3& v ) const
//    {
//        std::size_t res = 17;
//        res = res * 31 + std::hash<int>{}( v.x );
//        res = res * 31 + std::hash<int>{}( v.y );
//        res = res * 31 + std::hash<int>{}( v.z );
//        return res;
//    }
//};

namespace pce {

//using Entity = uint32_t;
//using VertexId = uint32_t;
//using FaceId = uint32_t;
//using EdgeId = uint32_t;
//
//
//using VertexMap = std::unordered_map<VertexId, glm::dvec3>;
//using VertexVertexMap = std::unordered_map<VertexId, std::vector<VertexId>>;
//using VertexPixelMap = std::unordered_map<VertexId, std::pair<int, int>>;
//using VertexDistanceMap = std::unordered_map<VertexId, double>; //!< distance from camera position
//using FaceVertexMap = std::unordered_map<FaceId, std::vector<VertexId>>;
//using EdgeMap = std::unordered_map<EdgeId, std::pair<VertexId, VertexId>>;
//using FaceEdgeMap = std::unordered_map<FaceId, std::vector<EdgeId>>;
//using IndexFaceMap = std::unordered_map<glm::ivec3,FaceId>;
//using FaceIndexMap = std::unordered_map<FaceId, glm::ivec3>;
//using IndexVertexMap = std::unordered_map<glm::ivec3, VertexId>;
//using VertexIndexMap = std::unordered_map<uint32_t, glm::ivec3>;
//using EntityFaceCollisionMap = std::unordered_map<Entity, FaceId>;
//using EntityVertexCollisionMap = std::unordered_map<Entity, VertexId>;
//using EntityEdgeCollisionMap = std::unordered_map<Entity, EdgeId>;
//using EntityIndexCollisionMap = std::unordered_map<Entity, std::vector<glm::ivec3>>;
//using EntityTimeCollisionMap = std::unordered_map<Entity, double>;
//using FaceCornerMap = std::unordered_map<uint32_t, glm::dvec3>;
////!< TODO: Understand what these maps are and name the types accordingly (1/3 of the way done)
//using FaceVertexCornerMap = std::unordered_map<FaceId, std::unordered_map<uint32_t, uint32_t>>;
//using VertexFaceCornerMap = std::unordered_map<VertexId, std::unordered_map<uint32_t, uint32_t>>;
//using FaceToCollisionElasticityComponent = std::unordered_map<FaceId, double>;

typedef std::unordered_map<uint32_t, glm::dvec3> MapIdToDvec3;
typedef std::unordered_map<uint32_t, std::vector<uint32_t>> MapIdToIdVect;
typedef std::unordered_map<uint32_t, std::pair<int, int>> MapIdToIntPair;
typedef std::unordered_map<uint32_t, double> MapIdToDouble;
typedef std::unordered_map<uint32_t, std::pair<uint32_t, uint32_t>> MapIdToIdPair;
//typedef std::unordered_map<glm::dvec3, uint32_t, KelpHasher<glm::dvec3>> MapDvec3ToId;
//typedef std::unordered_map<glm::dvec3, uint32_t> MapDvec3ToId;
typedef std::unordered_map<uint32_t, std::vector<glm::dvec3>> MapIdToDvec3Vect;
typedef std::unordered_map<uint32_t, uint32_t> MapIdToId;
typedef std::unordered_map<uint32_t, MapIdToId> MapIdToIdsMap;

struct RigidObject
{
    double radius;  // if == 0, then not a sphere
    double mass;

    bool is_deadbod;
    bool is_restingbod;
    bool is_complex_livebod;

    MapIdToDvec3  vertices;
    MapIdToIdVect vertex_vertex_map;
    MapIdToIdPair edges;
    MapIdToIdVect face_vertex_map;
    MapIdToIdVect vertex_edge_map;
    MapIdToIdVect face_edge_map;

    uint32_t base_face_id;
    int      face_count;

    MapIdToDvec3   camera_transformed_vertices;
    MapIdToIntPair vertex_pixels;
    MapIdToDouble  vertex_distance_map;

    MapIdToDvec3  face_corner_map;
    MapIdToDvec3  camera_rotated_face_corner_map;
    MapIdToDouble face_elasticty_map;
    MapIdToIdsMap vertex_face_corner_map;
    MapIdToIdsMap face_vertex_corner_map;

    //MapDvec3ToId index_face_map;
    MapIdToDvec3 face_index_map;  
    //MapDvec3ToId index_vertex_map;
    MapIdToDvec3 vertex_index_map;

    MapIdToId        entity_face_collision_map;
    MapIdToId        entity_vertex_collision_map;
    MapIdToId        entity_edge_collision_map;
    MapIdToDvec3Vect entity_index_collision_map;
    MapIdToDouble    entity_time_collision_map;
};

} /* namespace pce */
#endif /* rigid_object_component_hpp */
