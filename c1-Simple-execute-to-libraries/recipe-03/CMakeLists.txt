cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(recipe-03 LANGUAGES CXX)

add_library(message-objs OBJECT Message.hpp Message.cpp)

set_target_properties(message-objs PROPERTIES POSITION_INDEPENDENT_CODE 1)

add_library(message-shared SHARED $<TARGET_OBJECTS:message-objs>)

add_library(message-static STATIC $<TARGET_OBJECTS:message-objs>)

add_executable(hello-world hello-world.cpp)

target_link_libraries(hello-world message-static)