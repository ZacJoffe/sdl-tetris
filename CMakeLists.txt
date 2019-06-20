cmake_minimum_required(VERSION 3.10)

project(Tetris)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2TTF REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB_RECURSE SRC "*.cpp" "*.hpp")

add_executable(Tetris ${SRC})
target_link_libraries(Tetris ${SDL2_LIBRARIES} ${SDL2TTF_LIBRARY})