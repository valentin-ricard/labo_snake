cmake_minimum_required(VERSION 3.22)
project(labo_sdl)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(labo_sdl src/main.cpp src/RingBuffer.cpp src/RingBuffer.h src/Screen.cpp src/Screen.h src/Snake.cpp src/Snake.h src/Position.cpp src/Position.h)
target_link_libraries(labo_sdl ${SDL2_LIBRARIES})
