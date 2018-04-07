cmake_minimum_required(VERSION 3.7)
project(ENSICAEN_GrandPrix_Pilote)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        include/track/track.h
        src/track/testTrack.c
        src/track/track.c
        makefile
        README.md src/anakin/anakin.c)

add_executable(ENSICAEN_GrandPrix_Pilote ${SOURCE_FILES})