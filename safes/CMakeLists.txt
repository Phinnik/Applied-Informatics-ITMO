cmake_minimum_required(VERSION 3.16.0)
project(safes)

add_library(SafeLongLongT  SafeLongLongT.cpp)
add_library(SafeCArrayT SafeCArrayT.cpp)

add_executable(main main.cpp)
target_link_libraries(main SafeLongLongT SafeCArrayT)