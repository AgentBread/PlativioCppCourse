cmake_minimum_required(VERSION 3.14.1)
project(20200602_Aufgabe4)

set(CMAKE_CXX_STANDARD 14)
set(CORE_HEADER_SRC ${PROJECT_SOURCE_DIR})

add_executable(20200602_Aufgabe4 aufgabe4.cpp)

include_directories(${CORE_HEADER_SRC})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")