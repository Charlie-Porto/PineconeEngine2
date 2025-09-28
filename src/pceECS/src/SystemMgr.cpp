#include "SystemMgr.hpp"

namespace pce {


void SystemMgr::EntityDestroyed(Entity entity)
{
    for (auto const& pair : systems)
        pair.second->entities.erase(entity);
}


void SystemMgr::EntitySignatureChanged(Entity entity, Signature entitySig)
{
    for (auto const& pair : systems)
    {
        auto const& type = pair.first;
        auto const& system = pair.second;
        auto const& systemSig = signatures[type];
        bool if_retain_entity = true;

        // check if system components are present in entity sig
        for (size_t i = 0; i < systemSig.size(); ++i)
        {
            if (systemSig[i]) {
                if (!entitySig[i]) {
                    if_retain_entity = false;
                    break;
                }
            }
        }
        if (!if_retain_entity)
            system->entities.erase(entity);
        else
            system->entities.insert(entity);
    }
}

} /* namespace pce */
