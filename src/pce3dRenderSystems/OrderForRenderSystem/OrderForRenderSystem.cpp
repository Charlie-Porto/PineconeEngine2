#include "OrderForRenderSystem.hpp"

#include "util/orderForRenderFunctions.hpp"
#include "util/orderTag.hpp"
#include "util/OrderRenderListNode.hpp"

#include <pceComponents/render_component.hpp>
#include <pceComponents/order_of_render_registration_component.hpp>

#include <pceECS/ControlPanel.hpp>

#include <pceLogger/pceLogger.hpp>

#include <algorithm>


//extern ControlPanel control;


namespace pce {

namespace {
const std::string log_name = "OrderForRenderSystem";
} /* namespace */

OrderForRenderSystem::OrderForRenderSystem(ControlPanel* control)
  : ISystem(control)
{}

void OrderForRenderSystem::updateEntities(std::vector<std::pair<uint32_t, double>> order_of_ordering) 
{
    order_list_.clear();
    if (order_of_ordering.empty())
    {
        LOG_DEBUG(log_name) << "order of ordering vector is empty";
        return;
    }

    //!< Proceed with update functionality 
    size_t i = 0;
    size_t limit = 1;
    std::shared_ptr<orderTag> head_node_tag = nullptr;

    for (; i < limit; ++i)
    {
        Entity entity = order_of_ordering[i].first;
        if (!control->EntityExists(entity))
        {
            order_of_ordering.erase(order_of_ordering.begin() + i);
            continue;
        }

        //!< Retreive entity data
        auto&       render = control->GetComponent<OrderOfRenderRegistration>(entity);
        auto const& radar = control->GetComponent<Radar>(entity);
        auto const& rigid_object = control->GetComponent<RigidObject>(entity);

        head_node_tag.reset( new orderTag{radar, rigid_object} );
        head_node_tag->entity = entity;
        head_node_tag->closest_vertex_distance = radar.closest_vertex_distance;
        assert(rigid_object.camera_transformed_vertices.find(radar.closest_vertex_id) != rigid_object.camera_transformed_vertices.end());
        head_node_tag->closest_vertex_location = rigid_object.camera_transformed_vertices.at(radar.closest_vertex_id);
        head_node_tag->farthest_vertex_distance = radar.farthest_vertex_distance;
    }

    //!< Create head node in Render Order Tree
    render_order::OrderRenderListNode* head_node = new render_order::OrderRenderListNode(head_node_tag);

    for(; !order_of_ordering.empty() && i < order_of_ordering.size(); ++i)
    {
        const Entity entity = order_of_ordering[i].first;

        if (!control->EntityExists(entity))
            continue;

        auto&       render = control->GetComponent<OrderOfRenderRegistration>(entity);
        auto const& radar = control->GetComponent<Radar>(entity);
        auto const& rigid_object = control->GetComponent<RigidObject>(entity);

        std::shared_ptr<orderTag> order_tag_{ new orderTag{radar, rigid_object} };
        order_tag_->entity = entity;
        order_tag_->closest_vertex_distance = radar.closest_vertex_distance;
        assert(rigid_object.camera_transformed_vertices.find(radar.closest_vertex_id) != rigid_object.camera_transformed_vertices.end());
        order_tag_->closest_vertex_location = rigid_object.camera_transformed_vertices.at(radar.closest_vertex_id);
        assert(rigid_object.camera_transformed_vertices.find(radar.farthest_vertex_id) != rigid_object.camera_transformed_vertices.end());
        order_tag_->farthest_vertex_distance = radar.farthest_vertex_distance;

        render_order::OrderRenderListNode* node = new render_order::OrderRenderListNode(order_tag_);

        //!< TODO: Fix this function so it can handle cylinders
        head_node->InsertNodeInTree(node);
    }

    //!< Roll the Render Order Tree up into a 1 dimensional array so we know precisely which order in which we should render the objects
    order_list_ = head_node->GetListAtNode();
    //LOG_DEBUG(log_name) << "render order: ";
    //for (const auto& entity : order_list_)
    //    LOG_DEBUG(log_name) << '\t' << entity;
    delete head_node;
}

} /* namespace pce */
