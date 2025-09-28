#include "ComponentMgr.hpp"

namespace pce {

void ComponentMgr::EntityDestroyed(Entity entity)
{
    for (auto const& pair : component_arrays)
    {
        auto const& component = pair.second;
        component->EntityDestroyed(entity);
    }
}


} /* namespace pce */
