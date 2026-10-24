cmake_minimum_required(VERSION 3.25)
project(poker_solver LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(PS_BUILD_TESTS "Build unit and stress tests" ON)
option(PS_BUILD_BENCH "Build Google Benchmark targets" ON)

include(FetchContent)

# Solver library. Header-only until the first component lands in src/.
add_library(ps INTERFACE)
target_include_directories(ps INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(ps INTERFACE -Wall -Wextra -Wpedantic -Wconversion)

if(PS_BUILD_TESTS)
  FetchContent_Declare(googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP ON)
  set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)
  enable_testing()
  add_subdirectory(tests)
endif()

if(PS_BUILD_BENCH)
  FetchContent_Declare(benchmark
    URL https://github.com/google/benchmark/archive/refs/tags/v1.9.1.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP ON)
  set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
  set(BENCHMARK_ENABLE_INSTALL OFF CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(benchmark)
  add_subdirectory(bench)
endif()
