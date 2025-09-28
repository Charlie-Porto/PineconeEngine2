cmake_minimum_required(VERSION 3.21)

if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif()

set (PROJ pceCamera)
project(${PROJ})

add_definitions(-DDEBUG) # Comment out to build without debug logging

file (GLOB HEADERS src/*.hpp)
file (GLOB SOURCES src/*.cpp)
add_library(${PROJ} SHARED
    ${SOURCES}
)
message (STATUS "${HEADERS}")

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
        PUBLIC_HEADER DESTINATION include/${PROJ})

target_link_libraries(${PROJ} PRIVATE
    pceLogger
    pceMaths
    #pceUtils
)
