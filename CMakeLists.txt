cmake_minimum_required(VERSION 3.1.0)
project(sdl2_demo VERSION 0.1.0)

#include(CTest)
#enable_testing()

find_package(SDL2 REQUIRED)
add_library(utilities SHARED IMPORTED)

file(GLOB_RECURSE CPP_FILES src/*.cpp)
file(GLOB_RECURSE HPP_FILES src/*.hpp)
add_executable(sdl2_demo ${CPP_FILES} ${HPP_FILES})

target_link_libraries(sdl2_demo ${SDL2_LIBRARIES} GL ${CMAKE_CURRENT_SOURCE_DIR}/include)
#set(CPACK_PROJECT_NAME $(PROJECT_NAME))
#set(CPACK_PROJECT_VERSION $(PROJECT_VERSION))
#INCLUDE(CPack)
