#ifndef orderForRenderFunctions_hpp
#define orderForRenderFunctions_hpp

#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>
#include <pceMaths/plane_functions.hpp>
#include "orderTag.hpp"
#include <pceMaths/quaternion_functions.hpp>
//#include "../DevRenderSystem.cpp" //!< TODO: add this


//extern ControlPanel control;
//extern pce3d::DevRenderSystem dev_render_system;

namespace pce3d {
namespace render_order {

uint32_t getCloserOfTwoOverlappingEntitiesToOrigin(const std::shared_ptr<orderTag> a_entity_tag,
                                                   const std::shared_ptr<orderTag> b_entity_tag);

uint32_t getCloserOfTwoEntitiesToOrigin(const std::shared_ptr<orderTag> a_entity_tag,
                                        const std::shared_ptr<orderTag> b_entity_tag);


void insertEntityIntoOrderMapBinary(const std::shared_ptr<orderTag> entity_tag,
                                    std::vector<std::shared_ptr<orderTag>>& order_list);


void insertEntityIntoOrderMapStartingAtEnd(const std::shared_ptr<orderTag> entity_tag,
                                           std::vector<std::shared_ptr<orderTag>>& order_list);

}
}



#endif /* orderForRenderFunctions_hpp */
