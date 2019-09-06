#include <benchmark/benchmark.h>

#include "Matrix.hpp"
#include "Routine.hpp"



static void BM_solve (benchmark::State & state)
{
    for (auto _ : state)
        Routine <int, 100> ();
}
BENCHMARK (BM_solve);



BENCHMARK_MAIN();
