#include "utils.hpp"

#include "impl1.hpp"
#include "impl2.hpp"
#include "impl3.hpp"
#include "impl4.hpp"
#include <iostream>
#include <unistd.h>

#define ITER 10
void BENCH(void (*f)(int, long*), const char* test_name,  const int size) {
    long* time_result = new long[size];
    for (size_t i = 0; i < ITER; i++) {
        usleep(1000);
        f(size, &time_result[i]);
    }
    long final_time = 0;
    for (int i = 0; i < ITER; i++) {
        final_time += time_result[i];
    }
    final_time = final_time / ITER;
    long final_time_ms = (long)(final_time / 1e+6);
    printf("[BENCH] %s %ld ms (%ld ns)\t Tested on %d iterations\n",
                    test_name, final_time_ms, final_time, ITER);
    delete[] time_result;
}

void impl1(const int size, long *time_result) {
    using namespace impl_1;
    double* a = new double[size];
    my_vector v;
    v.len = size;
    v.data = a;

    double res;
    genpi(a, size);
    double expected_result = calc_reference(a, size);
    TIME_START
    foo_bar(&v, &res);
    TIME_STOP
    TIME_CACL
    *time_result = _time_result_nanoseconds;

    compare_results(expected_result, res);
    delete[] a;
}

void impl2(const int size, long *time_result) {
    using namespace impl_2;
    double* a = new double[size];
    my_vector v;
    v.len = size;
    v.data = a;

    double res;

    genpi(a, size);
    double expected_result = calc_reference(a, size);
    TIME_START
    foo_bar(&v, res);
    TIME_STOP
    TIME_CACL
    *time_result = _time_result_nanoseconds;

    compare_results(expected_result, res);
    delete[] a;
}

void impl3(const int size, long *time_result) {
    using namespace impl_3;
    double* a = new double[size];
    my_vector v;
    v.len = size;
    v.data = a;

    double res;

    genpi(a, size);
    double expected_result = calc_reference(a, size);
    TIME_START
    foo_bar(&v, res);
    TIME_STOP
    TIME_CACL
    *time_result = _time_result_nanoseconds;

    compare_results(expected_result, res);
    delete[] a;
}


void impl4(const int size, long *time_result) {
    using namespace impl_4;
    double* a = new double[size];
    my_vector v;
    v.len = size;
    v.data = a;

    double res;

    genpi(a, size);
    double expected_result = calc_reference(a, size);
    TIME_START
    foo_bar(&v, res);
    TIME_STOP
    TIME_CACL
    *time_result = _time_result_nanoseconds;

    compare_results(expected_result, res);
    delete[] a;
}

int main() {
    const int size = 6666666;
    srand(time(NULL));
    BENCH(impl1, "Implementation1", size);
    BENCH(impl2, "Implementation2", size);
    BENCH(impl3, "Implementation3", size);
    BENCH(impl4, "Implementation4", size);
}
