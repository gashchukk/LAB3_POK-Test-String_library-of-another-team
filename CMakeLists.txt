#add_executable(lab3_strings_usage_shumskyi_hashchuk_arnauta main.cpp mystring.cpp benchmark_controller.h)

cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)



project(lab3_strings_usage_shumskyi_hashchuk_arnauta)
enable_testing()

include(FetchContent)

## Project-wide setup
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

# Externally provided libraries
FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.10.x)

FetchContent_Declare(googlebenchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG main) # need main for benchmark::benchmark

FetchContent_MakeAvailable(
        googletest
        googlebenchmark)

add_executable(lab3_strings_benchmark main.cpp mystring.hpp mystring.cpp benchmark_controller.h benchmark_controller.h)
target_link_libraries(lab3_strings_benchmark benchmark::benchmark)