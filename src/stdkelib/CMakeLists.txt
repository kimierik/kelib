
project(stdkelib VERSION 0.0.1)

#stdkelib depends on debugtools
set(STDKELIB_SOURCES "./stdkelib.c" "../debugging/debug.c")

add_library( stdkelib STATIC ${STDKELIB_SOURCES})

set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static")

target_link_libraries(stdkelib PRIVATE logger debugtools -static )

