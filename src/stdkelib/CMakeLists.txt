

project(stdkelib)
set(STDKELIB_SOURCES "./stdkelib.c")
add_library( stdkelib ${STDKELIB_SOURCES})

target_link_libraries(stdkelib debug logger )

