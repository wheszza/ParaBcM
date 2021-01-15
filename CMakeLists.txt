cmake_minimum_required(VERSION 3.15)
project(ParaBcM)

set(CMAKE_CXX_FLAGS "-std=c++14 -O3")

set(SOURCE_FILES ./main.cxx
                 ./graph.h
                 ./bcc.h
                 ./parse.h)
add_executable(ParaBcM ${SOURCE_FILES})