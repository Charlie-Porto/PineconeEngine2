cmake_minimum_required(VERSION 3.21)

if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif()

set (PROJ pceMaths)
project(${PROJ})

add_definitions(-DDEBUG) # Comment out to build without debug logging

#file (GLOB FN_HEADERS fns/*.hpp)
#file (GLOB FN_SOURCES fns/implementations/*.cpp)
#file (GLOB OBJ_HEADERS objs/*.hpp)
#set (HEADERS "")
#list (APPEND HEADERS ${FN_HEADERS} ${OBJ_HEADERS})
#message(STATUS "headers: ${HEADERS}")

file (GLOB HEADERS src/*.hpp)
file (GLOB SOURCES src/implementations/*.cpp)
add_library(${PROJ} STATIC
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
        PUBLIC_HEADER DESTINATION include)
    #install (DIRECTORY src/
    #     DESTINATION include
    #     FILES_MATCHING PATTERN "*.hpp")
#install(TARGETS ${PROJ}
#    LIBRARY DESTINATION lib)
    #     PUBLIC_HEADER DESTINATION include/${PROJ}
    #install (DIRECTORY fns/
    #         DESTINATION include/pceMaths/fns
    #         FILES_MATCHING PATTERN "*.hpp")
    #install (DIRECTORY objs/
    #         DESTINATION include/pceMaths/objs
    #         FILES_MATCHING PATTERN "*.hpp")

#target_link_libraries(${PROJ} PRIVATE
#    pceLogger
#)

add_subdirectory(examples)
