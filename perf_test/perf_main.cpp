#include <benchmark/benchmark.h>
#include "utils.hpp"
#include <chrono>

#include "impl1.hpp"
#include "impl2.hpp"
#include "impl3.hpp"

// #ifdef TEST_TIMERS
#define TIME_START              auto start = std::chrono::high_resolution_clock::now();
#define TIME_STOP               auto end   = std::chrono::high_resolution_clock::now();
#define TIME_CACL               auto elapsed_seconds =  \
                                std::chrono::duration_cast<std::chrono::duration<double>>(  \
                                                                            end - start);

#define TIME_PASS               state.SetIterationTime(elapsed_seconds.count());

#define TIME_FINISH_PASS        TIME_STOP \
                                TIME_CACL \
                                TIME_PASS

// #endif

static void IMPL1_Calculation(benchmark::State& state) {
    using namespace impl_1;
    for (auto _ : state) {
        double a[LENGTH];
        my_vector v = {LENGTH, a};
        double res;
        simple_generator(a, LENGTH);

        TIME_START
        foo_bar(&v, &res);
        TIME_FINISH_PASS
    }
}
BENCHMARK(IMPL1_Calculation)->UseManualTime();

static void IMPL2_Calculation(benchmark::State& state) {
    using namespace impl_2;

    for (auto _ : state) {
        double a[LENGTH];
        my_vector v = {LENGTH, a};
        double res;
        simple_generator(a, LENGTH);

        TIME_START
        foo_bar(&v, &res);
        TIME_FINISH_PASS
    }
}
BENCHMARK(IMPL2_Calculation)->UseManualTime();

static void IMPL3_Calculation(benchmark::State& state) {
    using namespace impl_3;

    for (auto _ : state) {
        double a[LENGTH];
        my_vector v = {LENGTH, a};
        double res;
        simple_generator(a, LENGTH);

        TIME_START
        foo_bar(&v, res);
        TIME_FINISH_PASS
    }
}
BENCHMARK(IMPL3_Calculation)->UseManualTime();


BENCHMARK_MAIN();
