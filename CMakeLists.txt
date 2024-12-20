cmake_minimum_required(VERSION 3.10)

set(CMAKE_TOOLCHAIN_FILE "D:/Application/vcpkg/scripts/buildsystems/vcpkg.cmake")

project(sdl_dino)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SDL2 CONFIG REQUIRED)


add_executable(${PROJECT_NAME} src/main.cpp src/trex.cpp src/utils.cpp src/cactus.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main)