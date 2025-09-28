cmake_minimum_required(VERSION 3.21)

if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif()

set (PROJ pceLogger)
project(${PROJ})

add_library(${PROJ} SHARED
    ${PROJ}.cpp
)

set_target_properties(${PROJ} PROPERTIES PUBLIC_HEADER "${PROJ}.hpp")

target_include_directories(${PROJ} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/${PROJ}>
)

install(TARGETS ${PROJ}
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include/${PROJ}
)


add_subdirectory(test)

