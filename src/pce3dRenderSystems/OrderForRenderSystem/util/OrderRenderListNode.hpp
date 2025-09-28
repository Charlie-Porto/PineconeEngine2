#ifndef OrderRenderListNode_hpp
#define OrderRenderListNode_hpp


#include "orderTag.hpp"

#include <pceComponents/rigid_object_component.hpp>
#include <pceComponents/radar_component.hpp>

#include <vector>


namespace pce {
namespace render_order {

class OrderRenderListNode
{
    OrderRenderListNode* close_child_;
    OrderRenderListNode* far_child_;
public:
    std::shared_ptr<orderTag> order_tag_;

    OrderRenderListNode(std::shared_ptr<orderTag> tag);
    ~OrderRenderListNode();
    void InsertNodeInTree(OrderRenderListNode* node);
    std::vector<uint32_t> GetListAtNode();
};

} /* namespace render_order */
} /* namespace pce */
#endif /* OrderRenderListNode_hpp */
