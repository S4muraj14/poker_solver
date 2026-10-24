#include <benchmark/benchmark.h>

// Placeholder; real benchmarks arrive with the evaluator.
static void BM_Noop(benchmark::State& state) {
  for (auto _ : state) benchmark::DoNotOptimize(0);
}
BENCHMARK(BM_Noop);
