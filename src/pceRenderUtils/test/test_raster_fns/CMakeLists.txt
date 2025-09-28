set (PROJ test_raster_fns)

add_executable(${PROJ}
    test_raster_fns.cpp
)

target_include_directories(${PROJ} PRIVATE
    /usr/local/include
)

target_link_libraries(${PROJ} PRIVATE
    pceSDL
    pceLogger
    pceRenderUtils
)
