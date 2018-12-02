#pragma once
#include <stdlib.h>
#include <time.h>

static void simple_generator(double *vect, long size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            vect[i] = (double)(1 + rand() % 4) / 1.003;
        } else {
            vect[i] = (double)(1 + rand() % 10) / 10;
        }
    }
}
