set (PROJ example1_render_circle)

add_executable(${PROJ}
    example1_render_circle.cpp
)

target_include_directories(${PROJ} PRIVATE
    /usr/local/include
)

target_link_libraries(${PROJ} PRIVATE
    pceRenderUtils
    pceSDL
    pceLogger
    SDL2
)
