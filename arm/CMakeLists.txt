cmake_minimum_required(VERSION 2.8)
project(arm)

add_executable(arm arm.cpp)
set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")
