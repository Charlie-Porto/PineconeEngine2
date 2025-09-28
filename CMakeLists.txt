cmake_minimum_required(VERSION 3.21)

#if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
#endif()

set (PROJ PineconeEngine2)
project(${PROJ})
set (SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)

#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/externals/<some_3rdparty_lib>/include)

#add_library(${PROJ} SHARED
#    ${SRC}/main.cpp
#)

add_definitions(-DDEBUG) # For use with pceLogger

#add_subdirectory(kelp_externals)
add_subdirectory(src)
add_subdirectory(examples)

#target_include_directories(${PROJ} PRIVATE
#    /usr/local/include
#)
#
#target_link_libraries(${PROJ} PRIVATE
#    pceLogger
#)

