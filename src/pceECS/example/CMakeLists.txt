set (PROJ pceECS_example)

add_executable(${PROJ}
    example.cpp
)

target_include_directories(${PROJ} PRIVATE
    /usr/local/include
)

target_link_libraries(${PROJ} PRIVATE
    pceECS
)
