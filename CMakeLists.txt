cmake_minimum_required(VERSION 3.7)
project(ENSICAEN_GrandPrix_Pilote)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        include/track.h
        src/testTrack.c
        src/track.c
        makefile
        README.md src/anakin.c src/driver.c include/driver.h src/vector.c include/vector.h src/Controller.c include/Controller.h src/point.c include/point.h)

add_executable(ENSICAEN_GrandPrix_Pilote ${SOURCE_FILES})