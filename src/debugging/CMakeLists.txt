
project(debugtools VERSION 0.0.1)

set(DEBUG_SOURCES "./debug.c")

add_library( debugtools STATIC ${DEBUG_SOURCES})

set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static")

target_link_libraries(debugtools logger stdkelib)
