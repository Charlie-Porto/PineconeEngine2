#include "EntityMgr.hpp"
#include <cassert>

namespace pce {
EntityMgr::EntityMgr() 
{
    // Fill Available Entities queue with all possible entities 
    for (int i = 0; i < MAX_ENTITIES; ++i) 
    {
        availableEntities.push(i);
    }
}

Entity EntityMgr::CreateEntity()
{   
    // ensure room is available
    assert(activeEntityCount < MAX_ENTITIES);

    Entity id = availableEntities.front();
    availableEntities.pop();
    ++activeEntityCount;
    activeEntityHistory[id] = true;

    return id;
}

void EntityMgr::DestroyEntity(Entity entity)
{
    // Ensure entity is in set of those which can be deleted
    assert(entity < MAX_ENTITIES);

    signatures[entity].reset();
    availableEntities.push(entity);
    activeEntityHistory[entity] = false;
    --activeEntityCount;
}

void EntityMgr::SetSignature(Entity entity, Signature signature)
{
    assert(entity < MAX_ENTITIES);
    signatures[entity] = signature;
}

Signature EntityMgr::GetSignature(Entity entity)
{
    return signatures[entity];
}

} /* namespace pce */
