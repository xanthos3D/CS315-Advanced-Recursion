cmake_minimum_required(VERSION 3.12)
project(cs315project2)

set(CMAKE_CXX_STANDARD 17)

add_executable(cs315project2 main.cpp parser.cpp reclists.cpp  reclists.hpp lex.cpp lex.hpp solutions.cpp solutions.hpp)