// Get vector elements multiplication

#pragma once
#define LENGTH 1000000

namespace impl_3 {
    struct my_vector {
        long len;
        double *data;
    };

    long my_vector_len(my_vector *v) {
        return v->len;
    }

    void foo_bar(my_vector *v, double &res)
    {
        double *vect = v->data;
        long vect_size = my_vector_len(v);
        res = 1;
        for (long i = 0; i < vect_size; i++) {
            res = res * vect[i];
        }
    }
}
