#include "OrderRenderListNode.hpp"
#include "orderForRenderFunctions.hpp"


namespace pce {
namespace render_order {

OrderRenderListNode::OrderRenderListNode(std::shared_ptr<orderTag> tag) : order_tag_{tag}, close_child_{nullptr}, far_child_{nullptr} {}
OrderRenderListNode::~OrderRenderListNode()
{
    if (close_child_ != nullptr)
        delete close_child_;
    if (far_child_ != nullptr)
        delete far_child_;
}

void OrderRenderListNode::InsertNodeInTree(OrderRenderListNode* node)
{
    uint32_t closer_entity
        = pce::render_order::getCloserOfTwoEntitiesToOrigin(order_tag_, node->order_tag_);

    if (closer_entity == order_tag_->entity)
    {
        if (far_child_ == nullptr) { far_child_ = node; }
        else { far_child_->InsertNodeInTree(node); }
    }
    else 
    {
        if (close_child_ == nullptr) { close_child_ = node; }
        else { close_child_->InsertNodeInTree(node); }
    }
}


std::vector<uint32_t> OrderRenderListNode::GetListAtNode()
{ 
    std::vector<uint32_t> list = {order_tag_->entity};
    if (close_child_ != nullptr)
    {
        std::vector<uint32_t> close_child_list = close_child_->GetListAtNode();
        list.insert(list.end(), close_child_list.begin(), close_child_list.end());
    }
    if (far_child_ != nullptr)
    {
        std::vector<uint32_t> far_child_list = far_child_->GetListAtNode();
        far_child_list.insert(far_child_list.end(), list.begin(), list.end());
        return far_child_list;
    }
    return list;
}


} /* namespace render_order */
} /* namespace pce */
