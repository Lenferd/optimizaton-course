#include <iostream>
#include "impl1.hpp"
#include "generator.hpp"
int main() {

    using namespace impl_1;
    double a[LENGTH];
    my_vector v;
    v.len = LENGTH;
    v.data = a;

    double res;

    simple_generator(a, LENGTH);
    foo_bar(&v, &res);
    printf("res: %lf\n", res);
}
