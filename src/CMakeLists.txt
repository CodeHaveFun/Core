

add_executable(core
    core.cpp
)
# Add library code
add_subdirectory(cli)
add_subdirectory(tools)


target_link_libraries(core PRIVATE CoreCLI)
target_link_libraries(core PRIVATE Tools)