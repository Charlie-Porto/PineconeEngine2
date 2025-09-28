#ifndef RegisterForOrderOfRenderSystem_hpp
#define RegisterForOrderOfRenderSystem_hpp

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
a prep-only system that establishes an ordering of all elements to be used
by the OrderOfRenderSystem to determine the actual order of rendering
of entites.

This system helps to prevent unclean render ordering due to comparisons of 
large entities to small entities, as opposed to small entities to large entities 
-----------------------------------------------------------------*/

#include <utility>
#include <vector>
#include <pceECS/System.hpp>

namespace pce {
class RegisterForOrderOfRenderSystem : public ISystem 
{
public:
    RegisterForOrderOfRenderSystem(ControlPanel* control);

    void registerForOrderOfRenderSystem();

    std::vector<std::pair<uint32_t, double>> order_of_ordering_;
};
} /* namespace pce */
#endif /* RegisterForOrderOfRenderSystem_hpp */
