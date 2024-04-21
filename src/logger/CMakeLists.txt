
project(logger VERSION 0.0.1)

#logger depends on debugtools and stdkelib
set(LOGGER_SOURCES "./logger.c" "../debugging/debug.c" "../stdkelib/stdkelib.c")

add_library( logger ${LOGGER_SOURCES})

set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static")

target_link_libraries( logger stdkelib debugtools )


