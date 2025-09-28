set (PROJ pceRenderPipelineSDL_example2_more_spheres)

add_executable(${PROJ}
    example2_more_spheres.cpp
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
