set (PROJ pceRenderPipelineSDL_example1_basic_spheres)

add_executable(${PROJ}
    example1_basic_spheres.cpp
)

target_include_directories(${PROJ} PRIVATE
    /usr/local/include
)

target_link_libraries(${PROJ} PRIVATE
    pceRenderPipeline
    pceSDL
    pceLogger
    pceECS
    pceEntityForging
)
