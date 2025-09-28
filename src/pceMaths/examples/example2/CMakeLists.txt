cmake_minimum_required(VERSION 3.21)

if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif()

set (PROJ pceMath_example2_vec3_times_quat)
project(${PROJ})

### Options ###
option(BUILD_EXAMPLES "" ON)
### END Options

#add_definitions(-DDEBUG) # Comment out to build without debug logging

add_executable(${PROJ}
    example2_vec3_times_quat.cpp
)

#TODO: eliminate the need for this
target_include_directories(${PROJ} PRIVATE
    /usr/local/include
)

#install(TARGETS ${PROJ}
#     LIBRARY DESTINATION lib
#     PUBLIC_HEADER DESTINATION include/${PROJ}
#)

target_link_libraries(${PROJ} PRIVATE
    pceLogger
    pceMaths
)
