cmake_minimum_required(VERSION 3.10)
# Project Name: CirrusRT
project(CirrusRT)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Link directory for Assimp
link_directories(third-party/assimp/)
link_directories(third-party/glfw/lib-vc2022/)

# Adding third-party/nvrhi as subdirectory to build nvrhi along with CirrusRT
set(NVRHI_WITH_VULKAN ON)
add_subdirectory(third-party/donut)

# Source Files glob for LibCirrusRT
file(GLOB source_files src/*)
# Creating LibCirrusRT
add_library(Lib${PROJECT_NAME} STATIC ${source_files})
target_include_directories(Lib${PROJECT_NAME} PUBLIC ./include/)
target_include_directories(Lib${PROJECT_NAME} PUBLIC ./third-party/)
target_include_directories(Lib${PROJECT_NAME} PUBLIC ./third-party/glfw/include/)
target_include_directories(Lib${PROJECT_NAME} PUBLIC ./third-party/assimp/include/)
target_include_directories(Lib${PROJECT_NAME} PUBLIC ./third-party/donut/include/)

# Adding CirrusRT.exe executable
add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ./include/)

# Linking LibCirrusRT and assimp-vc143-mt.lib
target_link_libraries(${PROJECT_NAME} PRIVATE Lib${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} PUBLIC assimp-vc143-mt)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw3_mt.lib)

# Copying assimp-vc-143-mt.dll from third-party/assimp/ to build/
configure_file(third-party/assimp/assimp-vc143-mt.dll ${CMAKE_CURRENT_BINARY_DIR}/assimp-vc143-mt.dll COPYONLY)
# Setting CirrusRT.exe's runtime output directory to CMake's current binary directory
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
