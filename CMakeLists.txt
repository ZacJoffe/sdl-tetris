cmake_minimum_required(VERSION 3.10)

project(tetris)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2TTF REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

#file(GLOB SOURCES "*.cpp" "*.hpp" "src/*.cpp" "src/*.hpp")
file(GLOB SOURCE_HPP "${CMAKE_SOURCE_DIR}/src/*.hpp")
file(GLOB SOURCE_CPP "${CMAKE_SOURCE_DIR}/src/*.cpp")

SET(SOURCES ${SOURCE_CPP} ${SOURCE_HPP})

add_executable(tetris ${SOURCES})
target_link_libraries(tetris ${SDL2_LIBRARIES} ${SDL2TTF_LIBRARY})