

add_executable(core
    core.cpp


)
# Add library code
add_subdirectory(cli)
add_subdirectory(tools)
add_subdirectory(lexical)
add_subdirectory(errors)

target_link_libraries(core PRIVATE CoreCLI)
target_link_libraries(core PRIVATE Tools)
target_link_libraries(core PRIVATE LexicalPart)
target_link_libraries(core PRIVATE errorsPart)