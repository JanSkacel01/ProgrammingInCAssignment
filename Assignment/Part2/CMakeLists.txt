cmake_minimum_required(VERSION 3.26)
project(Part2 C)

set(CMAKE_C_STANDARD 11)



add_library(GenSet SHARED GenSetLibrary/GenSet.c)

add_executable(testAPP GenSetInterface.c)
target_link_libraries(testAPP GenSet)
