project(koan)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(./src SRC_LIST)
list(APPEND CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
include_directories(C:/SDL-2.0.3/include/SDL2)
link_directories(C:/SDL-2.0.3/lib)
link_libraries(MinGW32 SDL2main SDL2_image SDL2_ttf SDL2_mixer SDL2)
add_executable(${PROJECT_NAME} ${SRC_LIST})

