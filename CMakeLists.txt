cmake_minimum_required(VERSION 3.20)
project(Lab2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab2 tictactoe.cpp GameState.cpp GameState.h playMove.cpp globals.h)
