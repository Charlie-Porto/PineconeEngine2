cmake_minimum_required(VERSION 3.21)

if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif()

set (PROJ pceOrderForRenderSystem)
project(${PROJ})

add_library(${PROJ} SHARED
    OrderForRenderSystem.cpp
    util/OrderRenderListNode.cpp
    util/orderForRenderFunctions.cpp
    util/orderTag.cpp
)

set_target_properties(${PROJ} PROPERTIES PUBLIC_HEADER "OrderForRenderSystem.hpp")

#TODO: eliminate the need for this
target_include_directories(${PROJ} PRIVATE
    /usr/local/include
)

target_include_directories(${PROJ} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include/${PROJ}>
)

install(TARGETS ${PROJ}
    LIBRARY DESTINATION lib
     PUBLIC_HEADER DESTINATION include/pce3dRenderSystems
)

target_link_libraries(${PROJ} PRIVATE
    pceLogger
    pceECS
    pceMaths
)
