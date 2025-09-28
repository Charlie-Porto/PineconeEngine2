#ifndef System_hpp
#define System_hpp

#include "EntityMgr.hpp"
#include <set>


namespace pce {

class ControlPanel;

class ISystem
{
public:
    std::set<Entity> entities;
    ControlPanel* control;

    ISystem(ControlPanel* _control)
      : control(_control)
    {}
    ~ISystem(){}
};
} /* namespace pce */
#endif /* System_hpp */
