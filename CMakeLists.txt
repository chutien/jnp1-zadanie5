cmake_minimum_required(VERSION 3.9)
project(jnp1_zadanie5)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        helper.cc
        helper.h
        decoration.cc
        decoration.h
        person.cc
        person.h)

add_executable(ChristmasTree ChristmasTree.cc helper.cc helper.h decoration.cc decoration.h person.cc person.h)
add_executable(miniTest miniTest.cc ${SOURCE_FILES})