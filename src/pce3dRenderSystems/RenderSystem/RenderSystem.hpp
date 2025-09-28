#ifndef RenderSystem_hpp
#define RenderSystem_hpp

/*----------------------------------------------------------------|
--------------------- System Description -------------------------|
system that handles the rendering of on-screen entities
-----------------------------------------------------------------*/
#include <pceECS/System.hpp>
#include <pceECS/ControlPanel.hpp>

#include <pceComponents/rigid_object_component.hpp>
#include <pceComponents/position_component.hpp>
#include <pceComponents/surface_component.hpp>

#include <pceLogger/pceLogger.hpp>

namespace {
constexpr const char* log_name_render_sys = "RenderSystem";
}


namespace pce {


template <typename RendererT>
class RenderSystem : public ISystem
{
    double zoom_index_ = 1.0;
    RendererT* renderer_ = nullptr;
public:
    RenderSystem(ControlPanel*);
    void setRenderer(RendererT*);
    void setOrdinaryZoomIndex(double);
    void updateEntities(const std::vector<uint32_t>& order_of_render);

};
} /* namespace pce */


#include <pceComponents/position_component.hpp>
#include <pceComponents/render_component.hpp>

#include <pceRenderUtils/render_fns_SDL.hpp>


namespace pce {
template <typename RendererT>
RenderSystem<RendererT>::RenderSystem(ControlPanel* control)
  : ISystem(control)
{}

template <typename RendererT>
void RenderSystem<RendererT>::setRenderer(RendererT* renderer)
{
    renderer_ = renderer;
}


template <typename RendererT>
void RenderSystem<RendererT>::setOrdinaryZoomIndex(double zoom_index)
{
    zoom_index_ = zoom_index;
}


template <typename RendererT>
void RenderSystem<RendererT>::updateEntities(const std::vector<uint32_t>& order_of_render)
{
    //LOG_DEBUG(log_name_render_sys) << "updating entities...";
    /* render objects in order of furthest from camera to closest */
    for (auto const& entity : order_of_render)
    {
        //LOG_DEBUG(log_name_render_sys) << "updating entity#: " << entity;
        //!< check if item is on screen
        auto const& position = control->GetComponent<Position>(entity);
        if (position.com_radar_pixel == std::nullopt)
        {
            //LOG_DEBUG(log_name_render_sys) << "NOT rendering entity.";
            continue;
        }
        auto const& render = control->GetComponent<Render<RendererT>>(entity);
        //auto const& radar = control->GetComponent<Radar>(entity);
        auto const& rigid_object = control->GetComponent<RigidObject>(entity);
        auto const& surface = control->GetComponent<Surface>(entity);
        auto const& shade = control->GetComponent<FaceShade>(entity);

        //!< For MVP: render a simple shape for all entities
        //if (rigid_object.radius != 0)
        //{
        //    //LOG_DEBUG(log_name_render_sys) << "Attempting to render circle at coordinates: "
        //    //    << position.com_radar_pixel->x << ", "
        //    //    << position.com_radar_pixel->y;
        //    render::renderCircle(renderer_,
        //                         position.com_radar_pixel->x,
        //                         position.com_radar_pixel->y,
        //                         rigid_object.radius * 700 / rigid_object.vertex_distance_map.at(1),
        //                         surface.color,
        //                         true /* fill */);
        //}
        if (render.render_fn != nullptr)
        {
            ComponentsRelevantToRender crtr{
                .position = position,
                .rigid_object = rigid_object,
                .surface = surface,
                .shade = shade
            };
            render.render_fn(renderer_, &crtr);
        }
        else
        {
            LOG_DEBUG(log_name_render_sys) << "NOT attempting render.";
        }
        


        ////!< handle rendering of sphere entities
        //if (rigid_object.radius != 0 && rigid_object.vertices.size() == 1)
        //{
        //    // render::renderSphereObject(surface, shade, rigid_object, position);
        //    if (rigid_object.vertex_distance_map.at(1) < (20.0 * rigid_object.radius))
        //    {
        //        const std::vector<int> ncolor 
        //        = {int(surface.color[0] * shade.pixel_shade_map.at(position.center_of_mass_radar_pixel 
        //                                                           * ORDINARY_ZOOM_INDEX_)),
        //           int(surface.color[1] * shade.pixel_shade_map.at(position.center_of_mass_radar_pixel 
        //                                                           * ORDINARY_ZOOM_INDEX_)),
        //           int(surface.color[2] * shade.pixel_shade_map.at(position.center_of_mass_radar_pixel
        //                                                           * ORDINARY_ZOOM_INDEX_)),
        //           255};
        //        // quickdraw::drawFilledCircleClean(position.center_of_mass_radar_pixel, rigid_object.radius * 800.0 / rigid_object.vertex_distance_map.at(1), ncolor);
        //        quickdraw::drawFilledCircle(position.center_of_mass_radar_pixel, rigid_object.radius * 800.0 / rigid_object.vertex_distance_map.at(1), ncolor);
        //    }
        //    else
        //    {
        //        render::renderFilledCircleShaded(shade.pixel_shade_map, surface.color);
        //      // render::renderFilledCircleShadedWithVirtualPixels(shade.pixel_shade_map, surface.color, int(shade.virtual_pixel_ratio), shade.outline_pixels);
        //    }
        //}
        //// Render Cylinder
        //else if (rigid_object.radius != 0 && rigid_object.vertices.size() > 1)
        //{
        //    for (auto const& [id, vpair] : rigid_object.edges)
        //    {
        //        const glm::dvec3 a = rigid_object.camera_transformed_vertices.at(vpair.first);
        //        const glm::dvec3 b = rigid_object.camera_transformed_vertices.at(vpair.second);
        //        //dev_render_system.AddPointToPointColorMap(a, {55, 250, 25, 255}, 4.0);
        //        //dev_render_system.AddPointToPointColorMap(b, {55, 25, 250, 255}, 4.0);
        //        render::renderUnOrdinaryZoomedLine(rigid_object.vertex_pixels.at(vpair.first), rigid_object.vertex_pixels.at(vpair.second), surface.color);
        //    }
        //}

        ///* handle rendering of non-sphere entities */ 
        //else if (rigid_object.radius == 0 && !surface.is_transparent)
        //{
        //    // std::vector<std::pair<uint32_t, double>> faces_in_render_order = render::orderFacesByCameraProximity(
        //        // rigid_object.face_vertex_map, rigid_object.vertex_distance_map);

        //    // dev_render_system.AddPointToPointColorMap(rigid_object.camera_transformed_vertices.at(radar.closest_vertex_id), {0, 155, 55, 255}, 4.0);
        //    // std::cout << "calling faces order function" << '\n';
        //    std::vector<uint32_t> faces_in_render_order{};
        //    if (rigid_object.face_count == 6 || rigid_object.face_count == 1)
        //    {
        //      // std::cout << "getting rect faces ordered for render " << '\n';
        //      faces_in_render_order = render::getFacesOrderedForRender(radar.closest_vertex_id,
        //                                                               rigid_object.vertex_face_corner_map,
        //                                                               rigid_object.camera_rotated_face_corner_map);
        //    }
        //    else if (rigid_object.face_count == 4 || rigid_object.face_count == 5)
        //    {
        //      // std::cout << "getting pyramid faces ordered for render " << '\n';
        //      faces_in_render_order = render::getPyramidFacesOrderedForRender(
        //                                  radar.closest_vertex_id,
        //                                  rigid_object.base_face_id,
        //                                  rigid_object.camera_transformed_vertices,
        //                                  rigid_object.face_vertex_map,
        //                                  rigid_object.vertex_distance_map,
        //                                  rigid_object.vertex_face_corner_map,
        //                                  rigid_object.camera_rotated_face_corner_map);
        //    }

        //    for (size_t i = 0; i < faces_in_render_order.size(); ++i)
        //    {
        //        uint32_t face = faces_in_render_order[i];

        //        /* get face color */
        //        std::vector<int> face_color = surface.color;
        //        face_color[0] = int(double(face_color[0]) * shade.face_shade_map.at(face));
        //        face_color[1] = int(double(face_color[1]) * shade.face_shade_map.at(face));
        //        face_color[2] = int(double(face_color[2]) * shade.face_shade_map.at(face));

        //        std::vector<glm::dvec2> render_vertices{};
        //        size_t face_vertex_count = rigid_object.face_vertex_map.at(face).size();

        //        /* collect vertices */
        //        for (size_t j = 0; j < face_vertex_count; ++j)
        //            render_vertices.push_back(rigid_object.vertex_pixels.at(rigid_object.face_vertex_map.at(face)[j]));

        //      /* render each side of the non-sphere entity */
        //        if (face_vertex_count == 4)
        //        {
        //            auto quad = pce3d::maths::Quadrilateral{render_vertices[0], render_vertices[1], 
        //                                                    render_vertices[2],render_vertices[3]};
        //            quickdraw::drawFilledQuadrilateral(quad, face_color);
        //        }
        //        else if (face_vertex_count == 3)
        //        {
        //            auto tri = pce3d::maths::Triangle{render_vertices[0], render_vertices[1], render_vertices[2]};
        //            quickdraw::drawFilledTriangle(tri, face_color);
        //        }
        //    }
        //}
        //else if (rigid_object.radius == 0 && surface.is_transparent) 
        //{
        //    render::renderTransparentObject(rigid_object, surface.color);
        //}
    }
}



} /* namespace pce */

//#include "RenderSystem.cpp"

#endif /* RenderSystem_hpp */
