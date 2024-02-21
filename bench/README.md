# Notes

- https://github.com/google/benchmark

## Installation
```shell
git clone https://github.com/google/benchmark.git
cd benchmark
cmake -E make_directory "build"
cmake -E chdir "build" cmake -DBENCHMARK_DOWNLOAD_DEPENDENCIES=on -DCMAKE_BUILD_TYPE=Release ../
cmake --build "build" --config Release
```

## Usage
```cpp
#include <benchmark/benchmark.h>

// Function Declaration matters!
static void BM_SomeFunction(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    SomeFunction();
  }
}
// Register the function as a benchmark
BENCHMARK(BM_SomeFunction);
// Run the benchmark
BENCHMARK_MAIN();
```

## Compile
```shell
g++-13 $(src) --std=c++23 -lbenchmark -o bin/bench 
```
