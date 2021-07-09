cmake_minimum_required(VERSION 3.11)
project(pcc)

set(SRC
        src/main.cpp
        src/nfa.hpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

set(CMAKE_CXX_STANDARD 17)

add_executable(pcc ${SRC})