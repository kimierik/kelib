
project(debugtools VERSION 0.0.1)

set(DEBUG_SOURCES "./debug.c")
add_library( debugtools ${DEBUG_SOURCES})

target_link_libraries(debugtools logger stdkelib)
