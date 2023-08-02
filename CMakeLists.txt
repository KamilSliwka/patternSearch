cmake_minimum_required(VERSION 3.24)
project(patternSearch)

set(CMAKE_CXX_STANDARD 17)

add_executable(patternSearch main.cpp BoyerMoore.cpp BoyerMoore.h)
