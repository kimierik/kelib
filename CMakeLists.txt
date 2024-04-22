cmake_minimum_required(VERSION "3.19.2")


set(CMAKE_BUILD_TYPE Debug )
set(CMAKE_C_FLAGS_DEBUG "-O0 -g -Wall -ggdb -rdynamic")


project("kelib")

set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static")

set(SOURCES src/kelib.c src/debugging/debug.c src/logger/logger.c)


add_library(kelib ${SOURCES})

include(GNUInstallDirs)

install(TARGETS kelib
    PUBLIC_HEADER
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)


#add_executable("kelib" ${SOURCES})
