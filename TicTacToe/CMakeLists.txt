cmake_minimum_required(VERSION 3.20)
project(TicTacToePK)

set(CMAKE_CXX_STANDARD 14)

add_executable(TicTacToePK main.cpp Board.cpp Board.h Person.cpp Person.h Computer.cpp Computer.h Game.cpp Game.h)
