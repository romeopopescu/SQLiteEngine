cmake_minimum_required(VERSION 3.28)
project(SQLiteEngine)

set(CMAKE_CXX_STANDARD 17)

add_executable(SQLiteEngine main.cpp
        Row.h
        Column.h
        Functions.h
)
