cmake_minimum_required(VERSION 3.23)
project(awa C)

set(CMAKE_C_STANDARD 99)

add_executable(awa
        .h/add.h
        test/luogu/1010.c)


