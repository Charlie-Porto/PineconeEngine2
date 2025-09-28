cmake_minimum_required(VERSION 3.21)

if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif()

set (PROJ pceSDL)
project(${PROJ})

### Options ###
option(BUILD_EXAMPLES "" ON)
### END Options

add_definitions(-DDEBUG) # Comment out to build without debug logging

set (HEADERS
    src/CoreManager.hpp
    src/Simulation.hpp
    src/framerate_timer.hpp
    src/pceSDL.hpp
)

add_library(${PROJ} SHARED
    src/CoreManager.cpp
    src/Simulation.cpp
    src/framerate_timer.cpp
)

set_target_properties(${PROJ} PROPERTIES PUBLIC_HEADER "${HEADERS}")

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
     PUBLIC_HEADER DESTINATION include/${PROJ}
)

target_link_libraries(${PROJ} PRIVATE
    pceLogger
    SDL2
)

if (BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
