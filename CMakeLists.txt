cmake_minimum_required(VERSION 3.25)
project(OOPProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOPProject main.cpp World.cpp World.h Organism.h Animal.h Plant.h Plant.cpp Animal.cpp)

find_package(Curses REQUIRED)
set(CMAKE_CXX_FLAGS "-lncurses")