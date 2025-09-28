set (PROJ pceSDL_example1)

add_executable(${PROJ}
    example1.cpp
)

target_include_directories(${PROJ} PRIVATE
    /usr/local/include
)

target_link_libraries(${PROJ} PRIVATE
    pceSDL
    pceLogger
)
