
project(stdkelib VERSION 0.0.1)

set(STDKELIB_SOURCES "./stdkelib.c")
add_library( stdkelib ${STDKELIB_SOURCES})

target_link_libraries(stdkelib debugtools logger )

