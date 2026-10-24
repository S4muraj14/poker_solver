add_executable(ps_bench bench_main.cpp)
target_link_libraries(ps_bench PRIVATE ps benchmark::benchmark_main)
