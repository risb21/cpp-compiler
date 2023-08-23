cmake_minimum_required(VERSION 3.5.0)
project(cpp-compiler VERSION 0.1.0 LANGUAGES C CXX)

set(SOURCES main.cpp
            readme.cpp
            headers/Lexer.hpp)

add_executable(cpp-compiler ${SOURCES})