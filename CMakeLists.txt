cmake_minimum_required(VERSION "3.19.2")


set(CMAKE_BUILD_TYPE Debug )
set(CMAKE_C_FLAGS_DEBUG "-O0 -g -Wall -ggdb -rdynamic")


project("maintest")
add_subdirectory("src/debugging")
add_subdirectory("src/logger")
add_subdirectory("src/stdkelib")
add_executable("maintest" "src/main.c")
target_link_libraries(maintest logger debugtools stdkelib)
