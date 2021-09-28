cmake_minimum_required (VERSION 3.3.1)
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS "/EHsc ${CMAKE_CXX_FLAGS}")

PROJECT(quaternion)

# to .a file
# add_library(quaternion_shared SHARED ./src/quaternion.cpp)
# to .so file
add_library(quaternion_lib  STATIC ./src/quaternion.cpp)

# main to exe
add_executable(
quaternion ./src/main.cpp
)
target_link_libraries(quaternion quaternion_lib)




