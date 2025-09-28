#ifndef EntityMgr_hpp
#define EntityMgr_hpp

#include <bitset>
#include <queue>
#include <array>
#include <unordered_map>

namespace pce {


//!< Entity alii and constants
using Entity = uint32_t;
const int MAX_ENTITIES = 8000;

//!< Component alii and constants
using ComponentType = std::uint8_t;
const int MAX_COMPS = 20;

//!< Signature alii
using Signature = std::bitset<MAX_COMPS>;


/* -------------------- Entity Manager Class -------------------*/
class EntityMgr
{
    std::queue<int> availableEntities;
    std::array<Signature, MAX_ENTITIES> signatures{};
    int activeEntityCount{};
public:
    std::unordered_map<Entity, bool> activeEntityHistory{};
    EntityMgr();
    Entity CreateEntity();
    void DestroyEntity(Entity entity);
    void SetSignature(Entity entity, Signature signature);
    Signature GetSignature(Entity entity);
};

} /* namespace pce */
#endif /* EntityMgr_hpp */
