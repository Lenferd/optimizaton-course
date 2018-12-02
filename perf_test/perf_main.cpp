#include <benchmark/benchmark.h>
#include "generator.hpp"

#include "impl1.hpp"
#include "impl2.hpp"
#include "impl3.hpp"

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

static void IMPL2_Calculation(benchmark::State& state) {
    using namespace impl_2;
    double a[LENGTH];
    my_vector v = {LENGTH, a};
    double res;
    simple_generator(a, LENGTH);

    for (auto _ : state) {
        foo_bar(&v, &res);
    }
}
BENCHMARK(IMPL2_Calculation);

static void IMPL3_Calculation(benchmark::State& state) {
    using namespace impl_3;
    double a[LENGTH];
    my_vector v = {LENGTH, a};
    double res;
    simple_generator(a, LENGTH);

    for (auto _ : state) {
        foo_bar(&v, res);
    }
}
BENCHMARK(IMPL3_Calculation);


BENCHMARK_MAIN();
