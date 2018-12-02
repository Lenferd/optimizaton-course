#include <benchmark/benchmark.h>
#include "impl1.hpp"
#include "generator.hpp"

static void IMPL1_Calculation(benchmark::State& state) {
    using namespace impl_1;
    double a[LENGTH];
    my_vector v = {LENGTH, a};
    double res;
    simple_generator(a, LENGTH);

    for (auto _ : state) {
        foo_bar(&v, &res);
    }
}

BENCHMARK(IMPL1_Calculation);


BENCHMARK_MAIN();
