cmake_minimum_required(VERSION 3.21)

if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif()

set (PROJ pce3dRenderSystems)
project(${PROJ})

add_definitions(-DDEBUG)

add_subdirectory(RenderingOrderRegistrationSystem)
add_subdirectory(OrderForRenderSystem)
add_subdirectory(RenderSystem)
add_subdirectory(CameraOperatorSystem)
add_subdirectory(CameraTransformSystem)
add_subdirectory(RadarSystem)
add_subdirectory(ShadeSystem)
