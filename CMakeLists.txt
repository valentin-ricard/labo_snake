cmake_minimum_required(VERSION 3.22)
project(labo_sdl)

set(CMAKE_CXX_STANDARD 20)


if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    set(SDL2_INCLUDE_DIR libs/distrib/sdl2/include)
    set(SDL2_LIB_DIR libs/distrib/sdl2/lib/x64)
    include_directories(${SDL2_INCLUDE_DIR})
    link_directories(${SDL2_LIB_DIR})
else()
    find_package(SDL2 REQUIRED)
endif()

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(labo_sdl main.cpp)
target_link_libraries(labo_sdl ${SDL2_LIBRARIES})
