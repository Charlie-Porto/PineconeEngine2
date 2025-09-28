cmake_minimum_required(VERSION 3.21)

if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif()

set (PROJ pceRenderSystem)
project(${PROJ})

add_library(${PROJ} INTERFACE
    RenderSystem.hpp
)

set_target_properties(${PROJ} PROPERTIES PUBLIC_HEADER "RenderSystem.hpp")

#TODO: eliminate the need for this
target_include_directories(${PROJ} INTERFACE
    /usr/local/include
)

target_include_directories(${PROJ} INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include/${PROJ}>
)

install(TARGETS ${PROJ}
    # LIBRARY DESTINATION lib
     PUBLIC_HEADER DESTINATION include/pce3dRenderSystems
)

target_link_libraries(${PROJ} INTERFACE
    pceLogger
    pceECS
    pceMaths
    pceRenderUtils
)
