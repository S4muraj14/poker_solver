# Poker solver

Heads-up push/fold Nash solver in C++20. Correctness first, then speed.
Spec and theory: "Project week handbook" doc, https://claude.ai/artifact/ParyDfUWxiBUvN5s6JyNhd

## Commands
- Build: cmake --preset release && cmake --build --preset release
- Test with sanitizers: cmake --preset debug && cmake --build --preset debug && ctest --preset debug
- Benchmark: ./build/release/bench/ps_bench
- cmake, ninja, clang-format, clang-tidy, jq and gh live in ~/.local/bin

## Rules
- Piotr owns the design. For any new component, propose two or three designs
  with trade-offs and wait for him to choose.
- Every change comes with a test. Never weaken or delete a test to make it pass.
- Keep the brute-force reference implementations and stress-test fast code against them.
- No new dependencies without asking.
- After each component, add an entry to docs/DECISIONS.md: decision, alternatives, why.
- Comment anything non-obvious in one or two lines.

## Gotchas
- Benchmark numbers only count from release builds.
- Exploitability must come from an exact best response, never from sampling.
