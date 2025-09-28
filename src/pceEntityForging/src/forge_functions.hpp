#ifndef forge_functions_hpp
#define forge_functions_hpp

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
functions to assist the forge process
-----------------------------------------------------------------*/

#include <iostream>
#include <unordered_map>
#include <glm/vec3.hpp>
#include <pceMaths/quaternion_functions.hpp>

#include <pceComponents/rigid_object_component.hpp>

namespace pce {
namespace forge {


//using MapIdToDvec3 = std::unordered_map<uint32_t, glm::dvec3>;
//using MapIdToIdPair = std::unordered_map<uint32_t, std::vector<uint32_t>>;
//using VertexPixelMap = std::unordered_map<uint32_t, glm::dvec2>;
//using VertexDistanceMap = std::unordered_map<uint32_t, double>;
//using MapIdToIdVect = std::unordered_map<uint32_t, std::vector<uint32_t>>;
//using EdgeMap = std::unordered_map<uint32_t, std::pair<uint32_t, uint32_t>>;
//using FaceEdgeMap = std::unordered_map<uint32_t, std::vector<uint32_t>>;
//using IndexFaceMap = std::unordered_map<glm::ivec3, uint32_t>;
//using FaceIndexMap = std::unordered_map<uint32_t, glm::ivec3>;
//using IndexMapIdToDvec3 = std::unordered_map<glm::ivec3, uint32_t>;
//using VertexIndexMap = std::unordered_map<uint32_t, glm::ivec3>;
//using EntityFaceCollisionMap = std::unordered_map<uint32_t, uint32_t>;
//using EntityVertexCollisionMap = std::unordered_map<uint32_t, uint32_t>;
//using EntityEdgeCollisionMap = std::unordered_map<uint32_t, uint32_t>;
//using EntityIndexCollisionMap = std::unordered_map<uint32_t, std::vector<glm::ivec3>>;
//using EntityTimeCollisionMap = std::unordered_map<uint32_t, double>;
//using MapIdToDvec3 = std::unordered_map<uint32_t, glm::dvec3>;
//using MapIdToIdPair = std::unordered_map<uint32_t, std::unordered_map<uint32_t, uint32_t>>;
//using MapIdToIdPair = std::unordered_map<uint32_t, std::unordered_map<uint32_t, uint32_t>>;

//typedef std::unordered_map<uint32_t, glm::dvec3> MapIdToDvec3;
//typedef std::unordered_map<uint32_t, std::vector<uint32_t>> MapIdToIdVect;
//typedef std::unordered_map<uint32_t, std::pair<int, int>> MapIdToIntPair;
//typedef std::unordered_map<uint32_t, double> MapIdToDouble;
//typedef std::unordered_map<uint32_t, std::pair<uint32_t, uint32_t>> MapIdToIdPair;
////typedef std::unordered_map<glm::dvec3, uint32_t, KelpHasher<glm::dvec3>> MapDvec3ToId;
////typedef std::unordered_map<glm::dvec3, uint32_t> MapDvec3ToId;
//typedef std::unordered_map<uint32_t, std::vector<glm::dvec3>> MapIdToDvec3Vect;
//typedef std::unordered_map<uint32_t, uint32_t> MapIdToId;
//typedef std::unordered_map<uint32_t, MapIdToId> MapIdToIdsMap;


void rotateVertices(MapIdToDvec3& vertices, const double angle, const glm::dvec3& axis,
                    const glm::dvec3& center_of_gravity, bool vertices_normalized_to_object_center = false);


void createFaceVertexCornerMaps(const MapIdToDvec3& vertices, const MapIdToIdVect& faces,
                                MapIdToDvec3& face_corner_map,
                                MapIdToIdsMap& face_vertex_corner_map,
                                MapIdToIdsMap& vertex_face_corner_map,
                                const glm::dvec3& center_point,
                                bool vertices_normalized_to_object_center = false);

void createFaceEdgeMap(
    const MapIdToIdVect& face_vertex_map
  , const MapIdToIdPair& edge_map
  , MapIdToIdVect& face_edge_map
);


void createVertexEdgeMap(
    const MapIdToIdVect& vertex_vertex_map
  , const MapIdToIdPair& edge_map
  , MapIdToIdVect& vertex_edge_map
);


}
}




#endif /* forge_functions_hpp */
