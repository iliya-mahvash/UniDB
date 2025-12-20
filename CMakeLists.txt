cmake_minimum_required(VERSION 4.0)
project(UniDB)

set(CMAKE_CXX_STANDARD 14)

add_executable(main
        main.cpp
        parser/QueryParser.cpp
)