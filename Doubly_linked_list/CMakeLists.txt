cmake_minimum_required(VERSION 3.16)
project(DoublyLinkedList)

add_library(int_list_t int_list_t.h int_list_t.cpp)
add_executable(main main.cpp)
target_link_libraries(main int_list_t)
