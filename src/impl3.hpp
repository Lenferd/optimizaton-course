// Get vector elements multiplication

#pragma once
#include "utils.hpp"
#include <immintrin.h>

namespace impl_3 {
    struct my_vector {
        long len;
        double *data;
    };

    long my_vector_len(my_vector *v) {
        return v->len;
    }

    void foo_bar(my_vector *v, double &result)
    {
        double *vect = v->data;
        long vect_size = my_vector_len(v);

        __m256d result_v = _mm256_set_pd(1, 1, 1, 1);

        __m256d first_values;
        for (int i = 0; i < vect_size - 4; i += 4) {
            first_values    = _mm256_loadu_pd(vect + i);
            result_v        = _mm256_mul_pd(result_v, first_values);
        }

        result = 1;
        for (int i = 0; i < 4; i++) {
            result *= result_v[i];
        }

        // Calculate the rest
        for (int i = vect_size - 4; i < vect_size; ++i) {
            result *= vect[i];
        }

    }
}
