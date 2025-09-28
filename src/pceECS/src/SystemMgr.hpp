#ifndef SystemMgr_hpp
#define SystemMgr_hpp

#include "System.hpp"
#include "ComponentMgr.hpp"

namespace pce {
class SystemMgr
{
    std::unordered_map<const char*, Signature> signatures{};
    std::unordered_map<const char*, std::shared_ptr<ISystem>> systems{};
public:
    template <typename T> std::shared_ptr<T> RegisterSystem(ControlPanel* control);
    template<typename T> void SetSignature(Signature signature);
    void EntityDestroyed(Entity entity);
    void EntitySignatureChanged(Entity entity, Signature entitySig);
};



template <typename T>
std::shared_ptr<T> SystemMgr::RegisterSystem(ControlPanel* control)
{
    const char* type_name = typeid(T).name();
    auto system = std::make_shared<T>(control);
    systems.insert({type_name, system});
    return system;
}


template<typename T>
void SystemMgr::SetSignature(Signature signature)
{
    const char* type_name = typeid(T).name();
    signatures.insert({type_name, signature});
}


} /* namespace pce */
#endif /* SystemMgr_hpp */
