#include "ControlPanel.hpp"

namespace pce {

void ControlPanel::Init()
{
    mEntityManager = std::make_unique<EntityMgr>();
    mComponentManager = std::make_unique<ComponentMgr>();
    mSystemManager = std::make_unique<SystemMgr>();
}

ControlPanel::ControlPanel()
{
    Init();
}

//!< Entity Methods
Entity ControlPanel::CreateEntity()
{
    return mEntityManager->CreateEntity();
}

void ControlPanel::DestroyEntity(Entity entity)
{
    mEntityManager->DestroyEntity(entity);
    mComponentManager->EntityDestroyed(entity);
    mSystemManager->EntityDestroyed(entity);
}

bool ControlPanel::EntityExists(Entity entity)
{
    if (mEntityManager->activeEntityHistory.find(entity) != mEntityManager->activeEntityHistory.end())
        return mEntityManager->activeEntityHistory.at(entity);
    return false;
}

} /* namespace pce */
