cmake_minimum_required(VERSION 3.10)
project(ENSICAEN_GrandPrix_Pilote C)

set(CMAKE_C_STANDARD 11)

include_directories(include)
include_directories(lib/CCollections/include)
include_directories(lib/graph)

add_executable(ENSICAEN_GrandPrix_Pilote
        include/controller.h
        include/dijkstra.h
        include/driver.h
        include/graph.h
        include/point.h
        include/pointClement.h
        include/print.h
        include/track.h
        include/vector.h
        lib/CCollections/include/ArrayList.h
        lib/CCollections/include/CompareTo.h
        lib/CCollections/include/LinkedList.h
        lib/CCollections/include/PriorityQueue.h
        lib/CCollections/include/Queue.h
        lib/CCollections/include/Stack.h
        lib/CCollections/include/TreeSet.h
        lib/CCollections/include/util.h
        lib/CCollections/src/ArrayList.c
        lib/CCollections/src/CompareTo.c
        lib/CCollections/src/LinkedList.c
        lib/CCollections/src/PriorityQueue.c
        lib/CCollections/src/Queue.c
        lib/CCollections/src/Stack.c
        lib/CCollections/src/TreeSet.c
        #lib/graph/file.c
        #lib/graph/file.h
        #lib/graph/liste_adjacence.c
        #lib/graph/liste_ajdacence.h
        src/anakin2.c
        src/controller.c
        #src/dijkstra.c
        src/driver.c
        #src/graph.c
        src/point.c
        #src/print.c
        src/track.c
        src/vector.c)

add_executable(anakin
        src/anakinFull.c
        src/graph.c
        src/pointClement.c
        src/print.c
        src/dijkstra.c
        src/track.c
        include/graph.h
        include/pointClement.h
        include/print.h
        include/dijkstra.h
        include/track.h
        lib/graph/file.c
        lib/graph/file.h
        lib/graph/liste_adjacence.c
        lib/graph/liste_ajdacence.h
        lib/graph/testABR.c)
target_link_libraries(anakin m)

target_link_libraries(ENSICAEN_GrandPrix_Pilote m)
