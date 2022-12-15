cmake_minimum_required(VERSION 3.21)
project(wrapper_engine)

set(CMAKE_CXX_STANDARD 20)

add_executable(wrapper_engine main.cpp Wrapper.h Engine.cpp Engine.h Subject.h)
