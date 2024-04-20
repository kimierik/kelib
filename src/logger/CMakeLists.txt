

project(logger)
set(LOGGER_SOURCES "./logger.c")
add_library( logger ${LOGGER_SOURCES})

target_link_libraries(logger stdkelib debug )


