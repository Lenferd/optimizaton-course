// Get vector elements multiplication

#pragma once
#include "utils.hpp"

namespace impl_1 {
    struct my_vector {
        long len;
        double *data;
    };

    long my_vector_len(my_vector *v) {
        return v->len;
    }

    void foo_bar(my_vector *v, double *res)
    {
        long i;
        *res = 1;
        for (i = 0; i < my_vector_len(v); i++) {
            *res *= v->data[i];
        }
    }
}
