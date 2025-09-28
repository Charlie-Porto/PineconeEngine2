set (PROJ test_pceLogger)

add_executable(${PROJ}
    ${PROJ}.cpp
)

target_link_libraries(${PROJ} PUBLIC
    pceLogger
)

install(TARGETS ${PROJ} RUNTIME DESTINATION bin)
