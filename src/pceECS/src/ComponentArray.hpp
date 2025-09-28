#ifndef ComponentArray_hpp
#define ComponentArray_hpp

#include "EntityMgr.hpp"

namespace pce {
class IComponentArray
{
public:
    // functions for smooth inheritance
    virtual ~IComponentArray() = default;
    virtual void EntityDestroyed(Entity entity) = 0;
};

/*-------------- Component Array Class -------------*/
template <typename CompT> //!< Component Type
class ComponentArray : public IComponentArray
{
    std::array<CompT, MAX_ENTITIES> component_array; // the array containing entity data for the component
    std::unordered_map<Entity, int> entity_index_map; // mapping for organization
    std::unordered_map<int, Entity> index_entity_map; // mapping for organization
    int size_array_data; // total size of data inside of array 
public:
    void InsertData(Entity entity, CompT component);
    void RemoveData(Entity entity);
    CompT& GetData(Entity entity);
    void EntityDestroyed(Entity entity) override;
};



template<typename CompT>
void ComponentArray<CompT>::InsertData(Entity entity, CompT component)
{
    // ensure entity to index and index to entity maps agree 
    // assert(entity_index_map.find(entity) == index_entity_map.find(entity));

    // insert new entry
    int new_index = size_array_data;
    entity_index_map[entity] = new_index;
    index_entity_map[new_index] = entity;
    component_array[new_index] = component;

    ++size_array_data;
}


template<typename CompT>
void ComponentArray<CompT>::RemoveData(Entity entity)
{
    // Ensure item being removed is not last item
    // assert(entity_index_map.find(entity) != index_entity_map.end()); 
    
    // move last element into empty slot
    int index_removed = entity_index_map[entity];
    int index_oflast_item = size_array_data - 1;
    component_array[index_removed] = component_array[index_oflast_item];

    // update maps
    Entity entity_oflast_index = index_entity_map[index_oflast_item];
    entity_index_map[entity_oflast_index] = index_removed;
    index_entity_map[index_removed] = entity_oflast_index;

    entity_index_map.erase(entity);
    index_entity_map.erase(index_oflast_item);
    
    --size_array_data;
}


template<typename CompT>
CompT& ComponentArray<CompT>::GetData(Entity entity)
{
    return component_array[entity_index_map[entity]];
}


template<typename CompT>
void ComponentArray<CompT>::EntityDestroyed(Entity entity)
{
    if (entity_index_map.find(entity) != entity_index_map.end())
    {
        RemoveData(entity);
    }
}
} /* namespace pce */


#endif /* ComponentArray_hpp */
