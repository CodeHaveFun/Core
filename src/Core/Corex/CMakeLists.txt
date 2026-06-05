cmake_minimum_required(VERSION 3.10)

project(Corex)

# output exe
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# output .a/.lib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/BuildObj)

# include path
include_directories(lib/Uni)

# frontend object/library
add_library(fontendobj OBJECT
    Frontend/fontend.cpp
    Frontend/InputGetFile.cpp
    Frontend/LexerTokenCore.cpp
)
target_include_directories(fontendobj PRIVATE include)
# main exe
add_executable(core
    $<TARGET_OBJECTS:fontendobj>
    Core.cpp
)
# move dll runtime
add_custom_target(copy_files ALL
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_SOURCE_DIR}/lib/Uni/DLLFile/icudt79.dll"
    "${CMAKE_SOURCE_DIR}/bin/icudt79.dll"

    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_SOURCE_DIR}/lib/Uni/DLLFile/icuin79.dll"
    "${CMAKE_SOURCE_DIR}/bin/icuin79.dll"

    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_SOURCE_DIR}/lib/Uni/DLLFile/icuio79.dll"
    "${CMAKE_SOURCE_DIR}/bin/icuio79.dll"

    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_SOURCE_DIR}/lib/Uni/DLLFile/icutu79.dll"
    "${CMAKE_SOURCE_DIR}/bin/icutu79.dll"

    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_SOURCE_DIR}/lib/Uni/DLLFile/icuuc79.dll"
    "${CMAKE_SOURCE_DIR}/bin/icuuc79.dll"

)
# ICU link
target_link_libraries(core
    ${CMAKE_SOURCE_DIR}/lib/Uni/DLLFile/libicudt.dll.a
    ${CMAKE_SOURCE_DIR}/lib/Uni/DLLFile/libicuin.dll.a
    ${CMAKE_SOURCE_DIR}/lib/Uni/DLLFile/libicuio.dll.a
    ${CMAKE_SOURCE_DIR}/lib/Uni/DLLFile/libicutu.dll.a
    ${CMAKE_SOURCE_DIR}/lib/Uni/DLLFile/libicuuc.dll.a
)