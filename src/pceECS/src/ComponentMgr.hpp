#ifndef ComponentMgr_hpp
#define ComponentMgr_hpp

#include "ComponentArray.hpp"
#include <memory>
#include <typeinfo>

namespace pce {
class ComponentMgr 
{
    // Map of string to component array 
    std::unordered_map<const char*, std::shared_ptr<IComponentArray>> component_arrays{};
    // Map of string to component type
    std::unordered_map<const char*, int> component_types{};
    int next_component_type{};
    // function to get pointer (to type T)
    template<typename T> std::shared_ptr<ComponentArray<T>> GetComponentArray();
public:
    template<typename T> void RegisterComponent();
    template<typename T> int GetComponentType();
    template<typename T> void AddComponent(Entity entity, T component);
    template<typename T> void RemoveComponent(Entity entity);
    template<typename T> T& GetComponent(Entity entity);
    void EntityDestroyed(Entity entity);
};

template<typename T>
void ComponentMgr::RegisterComponent()
{
    const char* type_name = typeid(T).name();
    assert(component_types.find(type_name) == component_types.end());
    component_types.insert({type_name, next_component_type}); // add component to component type map
    component_arrays.insert({type_name, std::make_shared<ComponentArray<T>>()}); // create a pointer to the ComponentArray, and add to array map
    ++next_component_type; // incrememt component type ID
}


template<typename T>
int ComponentMgr::GetComponentType()
{
    const char* type_name = typeid(T).name();
    return component_types[type_name];
}


template<typename T>
void ComponentMgr::AddComponent(Entity entity, T component)
{
    GetComponentArray<T>()->InsertData(entity, component);
}


template<typename T>
void ComponentMgr::RemoveComponent(Entity entity)
{
    GetComponentArray<T>()->RemoveData(entity);
}


template<typename T>
T& ComponentMgr::GetComponent(Entity entity)
{
    return GetComponentArray<T>()->GetData(entity);
}



template<typename T>
std::shared_ptr<ComponentArray<T>> ComponentMgr::GetComponentArray()
{
    const char* type_name = typeid(T).name();

    // this return converts the IComponentArray pointer to a ComponentArray pointer (damn. sexy)
    return std::static_pointer_cast<ComponentArray<T>>(component_arrays[type_name]);
}


} /* namespace pce */
#endif /* ComponentMgr_hpp */
