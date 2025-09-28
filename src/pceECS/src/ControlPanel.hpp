#ifndef ControlPanel_hpp
#define ControlPanel_hpp

#include <memory>

#include "EntityMgr.hpp"
#include "ComponentMgr.hpp"
#include "SystemMgr.hpp"

namespace pce {

class ControlPanel
{
    std::unique_ptr<EntityMgr> mEntityManager;
    std::unique_ptr<ComponentMgr> mComponentManager;
    std::unique_ptr<SystemMgr> mSystemManager;
public:
	void Init();
    ControlPanel();

	Entity CreateEntity();
	void DestroyEntity(Entity entity);
    bool EntityExists(Entity entity);

	template<typename T> void RegisterComponent();
	template<typename T> void AddComponent(Entity entity, T component);
	template<typename T> void RemoveComponent(Entity entity);
	template<typename T> T& GetComponent(Entity entity);
	template<typename T> int GetComponentType();

	template<typename T> std::shared_ptr<T> RegisterSystem();
	template<typename T> void SetSystemSignature(Signature signature);

	template<typename T0, typename T1> void AssignSystemComponents();
	template<typename T0, typename T1, typename T2> void AssignSystemComponents();
	template<typename T0, typename T1, typename T2, typename T3> void AssignSystemComponents();
	template<typename T0, typename T1, typename T2, typename T3, typename T4> void AssignSystemComponents();
	template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5> void AssignSystemComponents();
	template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6> void AssignSystemComponents();
};



//!< Component methods
template<typename T>
void ControlPanel::RegisterComponent()
{
    mComponentManager->RegisterComponent<T>();
}

template<typename T>
void ControlPanel::AddComponent(Entity entity, T component)
{
    mComponentManager->AddComponent<T>(entity, component);

    auto signature = mEntityManager->GetSignature(entity);
    signature.set(mComponentManager->GetComponentType<T>(), true);
    mEntityManager->SetSignature(entity, signature);

    mSystemManager->EntitySignatureChanged(entity, signature);
}

template<typename T>
void ControlPanel::RemoveComponent(Entity entity)
{
    mComponentManager->RemoveComponent<T>(entity);

    auto signature = mEntityManager->GetSignature(entity);
    signature.set(mComponentManager->GetComponentType<T>(), false);
    mEntityManager->SetSignature(entity, signature);

    mSystemManager->EntitySignatureChanged(entity, signature);
}

template<typename T>
T& ControlPanel::GetComponent(Entity entity)
{
    return mComponentManager->GetComponent<T>(entity);
}

template<typename T>
int ControlPanel::GetComponentType()
{
    return mComponentManager->GetComponentType<T>();
}


//!< System methods
template<typename T>
std::shared_ptr<T> ControlPanel::RegisterSystem()
{
    return mSystemManager->RegisterSystem<T>(this);
}

template<typename T>
void ControlPanel::SetSystemSignature(Signature signature)
{
    mSystemManager->SetSignature<T>(signature);
}

// System methods for succint registration
template<typename T0, typename T1>
void ControlPanel::AssignSystemComponents()
{
    Signature sig;
    sig.set(GetComponentType<T1>());
    SetSystemSignature<T0>(sig);
}

template<typename T0, typename T1, typename T2>
void ControlPanel::AssignSystemComponents()
{
    Signature sig;
    sig.set(GetComponentType<T1>());
    sig.set(GetComponentType<T2>());
    SetSystemSignature<T0>(sig);
}

template<typename T0, typename T1, typename T2, typename T3>
void ControlPanel::AssignSystemComponents()
{
    Signature sig;
    sig.set(GetComponentType<T1>());
    sig.set(GetComponentType<T2>());
    sig.set(GetComponentType<T3>());
    SetSystemSignature<T0>(sig);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4>
void ControlPanel::AssignSystemComponents()
{
    Signature sig;
    sig.set(GetComponentType<T1>());
    sig.set(GetComponentType<T2>());
    sig.set(GetComponentType<T3>());
    sig.set(GetComponentType<T4>());
    SetSystemSignature<T0>(sig);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
void ControlPanel::AssignSystemComponents()
{
    Signature sig;
    sig.set(GetComponentType<T1>());
    sig.set(GetComponentType<T2>());
    sig.set(GetComponentType<T3>());
    sig.set(GetComponentType<T4>());
    sig.set(GetComponentType<T5>());
    SetSystemSignature<T0>(sig);
}

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
void ControlPanel::AssignSystemComponents()
{
    Signature sig;
    sig.set(GetComponentType<T1>());
    sig.set(GetComponentType<T2>());
    sig.set(GetComponentType<T3>());
    sig.set(GetComponentType<T4>());
    sig.set(GetComponentType<T5>());
    sig.set(GetComponentType<T6>());
    SetSystemSignature<T0>(sig);
}


} /* namespace pce */
#endif /* ControlPanel_hpp */
