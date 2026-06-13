set (PROJ pceRenderPipelineSDL_example3_basic_spheres)

add_executable(${PROJ}
    example3_cuboids.cpp
)

target_link_libraries(${PROJ} PRIVATE
    pceRenderPipeline
    pceSDL
    pceLogger
    pceECS
    pceEntityForging
)
