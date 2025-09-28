#ifndef OrderForRenderSystem_hpp
#define OrderForRenderSystem_hpp

#include <pceECS/System.hpp>

#include <unordered_map>
#include <utility>
#include <vector>


namespace pce {

class OrderForRenderSystem : public ISystem
{
    std::vector<uint32_t> particles_to_order_last_;
public:
    std::vector<uint32_t> order_list_;  //!< A list containing registered entities in the order they should be rendered so as to 
                                        //!< appear properly structured in space. Object is public so that it can be passed on to
                                        //!< the Render System.
    
    OrderForRenderSystem(ControlPanel*);
    void updateEntities(std::vector<std::pair<uint32_t, double>> order_of_ordering);
};

} /* namespace pce */
#endif /* OrderForRenderSystem_hpp */
