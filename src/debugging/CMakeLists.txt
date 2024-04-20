

project(debug)
set(DEBUG_SOURCES "./debug.c")
add_library( debug ${DEBUG_SOURCES})

target_link_libraries(debug logger stdkelib)
