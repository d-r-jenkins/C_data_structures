cmake_minimum_required(VERSION 3.15.0)
set(CMAKE_C_COMPILER "clang-12")
set(CMAKE_C_FLAGS "-Wall -pedantic -Wextra")

project(data_structures C)

aux_source_directory("source/" sources)
add_executable(test ${sources} tests/tests.c)
target_include_directories(test PUBLIC "include/")
target_compile_features(test PUBLIC c_std_99)
