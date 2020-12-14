cmake_minimum_required(VERSION 3.18)
project(c_test C)

set(CMAKE_C_STANDARD 99)

set(LIBS libs/queue_lib.c libs/string_lib.c libs/tree_lib.c)
SET(TESTS tests/test_queue_lib.c tests/test_string_lib.c tests/test_tree_lib.c)

include_directories(libs tests unity)
add_executable(c_test main.c unity/unity.c ${TESTS} ${LIBS})