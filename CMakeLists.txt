cmake_minimum_required(VERSION 3.10)
# Project Name: CirrusRT
project(CirrusRT)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3 /MP")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /D_ITERATOR_DEBUG_LEVEL=1")

# Link directory for Assimp
link_directories(third-party/assimp/)

set(NVRHI_WITH_VULKAN ON)
add_subdirectory(third-party/donut)

include_directories(
    include/
)

file(GLOB SOURCES "src/*.cpp" "include/*.h")

# Adding CirrusRT.exe executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Linking assimp-vc143-mt.lib
target_link_libraries(${PROJECT_NAME} donut_core donut_engine donut_app assimp-vc143-mt)

# Copying assimp-vc-143-mt.dll from third-party/assimp/ to build/
configure_file(third-party/assimp/assimp-vc143-mt.dll ${CMAKE_CURRENT_BINARY_DIR}/assimp-vc143-mt.dll COPYONLY)
# Setting CirrusRT.exe's runtime output directory to CMake's current binary directory
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

set(DONUT_SHADERS_OUTPUT_DIR ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
set(folder "shader")

include(third-party/donut/compileshaders.cmake)
file(GLOB shader "*.hlsl")

donut_compile_shaders_all_platforms(
    TARGET ${PROJECT_NAME}_shader
    CONFIG ${CMAKE_CURRENT_SOURCE_DIR}/shader/shader.cfg
    FOLDER ${folder}
    OUTPUT_BASE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/shader
)

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER ${folder})