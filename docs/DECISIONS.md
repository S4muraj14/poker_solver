# Design decisions

One entry per decision: what was chosen, the alternatives, and why.

## Build: CMake presets + FetchContent
- **Decision:** CMake with `debug` (ASan + UBSan) and `release` (`-O3 -march=native`) presets; GoogleTest and Google Benchmark fetched at configure time, pinned to release tarballs.
- **Alternatives:** system packages (versions vary across machines), git submodules (extra clone step).
- **Why:** one command builds anywhere, including CI, with the same dependency versions.
