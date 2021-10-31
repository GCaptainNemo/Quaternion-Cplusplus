cmake_minimum_required (VERSION 3.3.1)
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS "/EHsc ${CMAKE_CXX_FLAGS}")

PROJECT(quaternion)

add_executable(
quaternion  ./src/main.cpp
)




