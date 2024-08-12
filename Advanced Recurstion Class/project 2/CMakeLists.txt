cmake_minimum_required(VERSION 3.24)
project(project_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(reclistsStudentFiles)

add_executable(project_2
        reclistsStudentFiles/lex.cpp
        reclistsStudentFiles/lex.hpp
        reclistsStudentFiles/main.cpp
        reclistsStudentFiles/parser.cpp
        reclistsStudentFiles/reclists.cpp
        reclistsStudentFiles/reclists.hpp
        reclistsStudentFiles/solutions.cpp
        reclistsStudentFiles/solutions.hpp)
