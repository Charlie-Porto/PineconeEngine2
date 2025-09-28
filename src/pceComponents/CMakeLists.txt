cmake_minimum_required(VERSION 3.21)

if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif()

set (PROJ pceComponents)
project(${PROJ})

file(GLOB SOURCES src/*.hpp)
message(STATUS "sources : ${SOURCES}")

add_library(${PROJ} INTERFACE
    ${SOURCES}
)

set_target_properties(${PROJ} PROPERTIES PUBLIC_HEADER "${SOURCES}")

target_include_directories(${PROJ} INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include/${PROJ}>
)

install(TARGETS ${PROJ}
     LIBRARY DESTINATION lib
     PUBLIC_HEADER DESTINATION include/${PROJ}
)
