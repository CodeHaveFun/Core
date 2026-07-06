cmake_minimum_required(VERSION 3.10)

project(Corex)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# output exe
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# output .a/.lib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/BuildObj)

# include path
include_directories(${CMAKE_SOURCE_DIR}/lib/Uni)
include_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/language)
# frontend object/library
add_library(fontendobj OBJECT
    ${CMAKE_SOURCE_DIR}/Frontend/fontend.cpp
    ${CMAKE_SOURCE_DIR}/Frontend/InputGetFile.cpp
    ${CMAKE_SOURCE_DIR}/Frontend/lexical_analysis.cpp
    ${CMAKE_SOURCE_DIR}/Frontend/token_filter.cpp
    ${CMAKE_SOURCE_DIR}/Frontend/language.cpp
)
target_include_directories(fontendobj PRIVATE include)
# main exe
add_executable(core
    $<TARGET_OBJECTS:fontendobj>
    Core.cpp
)
# move dll runtime and package language
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

    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/include/language"
    "${CMAKE_SOURCE_DIR}/bin/language"


)
# ICU link
target_link_libraries(core
    ${CMAKE_SOURCE_DIR}/lib/Uni/DLLFile/libicudt.dll.a
    ${CMAKE_SOURCE_DIR}/lib/Uni/DLLFile/libicuin.dll.a
    ${CMAKE_SOURCE_DIR}/lib/Uni/DLLFile/libicuio.dll.a
    ${CMAKE_SOURCE_DIR}/lib/Uni/DLLFile/libicutu.dll.a
    ${CMAKE_SOURCE_DIR}/lib/Uni/DLLFile/libicuuc.dll.a
)