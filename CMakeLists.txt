cmake_minimum_required(VERSION "3.19.2")


set(CMAKE_BUILD_TYPE Debug )
set(CMAKE_C_FLAGS_DEBUG "-O0 -g -Wall -ggdb -rdynamic")


project("maintest")

set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static")

# stdkelib and logger depend on debugtools idk if this can cause issues with bin size

add_subdirectory("src/debugging")
set_target_properties(debugtools PROPERTIES PUBLIC_HEADER src/debugging/debug.h)

add_subdirectory("src/logger")
set_target_properties(logger PROPERTIES PUBLIC_HEADER src/logger/logger.h)

add_subdirectory("src/stdkelib")
set_target_properties(stdkelib PROPERTIES PUBLIC_HEADER src/stdkelib/stdkelib.h)



include(GNUInstallDirs)
install(TARGETS debugtools logger stdkelib
    PUBLIC_HEADER
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/stdkelib
)




add_executable("maintest" "src/main.c")
target_link_libraries(maintest logger debugtools stdkelib)
