#include <iostream>
#include "impl1.hpp"
#include "utils.hpp"


int main() {
    using namespace impl_1;
    double a[LENGTH];
    my_vector v;
    v.len = LENGTH;
    v.data = a;

    double res;

    correct_generator(a, LENGTH);
    double expected_result = calc_reference(a, LENGTH);
    TIME_START
    foo_bar(&v, &res);
    TIME_FINISH
    compare_results(expected_result, res);
}
