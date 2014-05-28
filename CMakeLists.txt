project(koan)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(./src SRC_LIST)
list(APPEND CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
include_directories(/usr/include/SDL2)
link_directories(/usr/lib)
link_libraries(-lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer)
add_executable(${PROJECT_NAME} ${SRC_LIST})

