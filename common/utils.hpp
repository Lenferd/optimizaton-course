#pragma once
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <limits>
#include <chrono>
#include <iostream>

#define LENGTH 1000000
#define VAL_NAME(val) #val

#define TIME_START              auto _time_start = std::chrono::high_resolution_clock::now();
#define TIME_STOP               auto _time_end   = std::chrono::high_resolution_clock::now();
#define TIME_CACL               auto _time_elapsed_seconds =                                        \
                                std::chrono::duration_cast<std::chrono::duration<double>>(          \
                                                                            _time_end - _time_start);\
                                auto _time_result_nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(_time_elapsed_seconds).count();

#define TIME_PRINT              printf("TIME : %ld ns\n", _time_result_nanoseconds);
#define TIME_FINISH             TIME_STOP TIME_CACL TIME_PRINT

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

static void correct_generator(double *vect, long size) {
    double temp_val = 1;
    for (int i = 0; i < size; i++) {
        double value;
        if (i % 2 == 0) {
            do {
                value = (double)(1 + rand() % 4);
            } while((temp_val * value) > 1e5 || (temp_val * value) < 1e-5);
            temp_val *= value;
            vect[i] = value;
        } else {
            do {
                value = (double)(1 + rand() % 10) / 10;
            } while((temp_val * value) > 1e5 || (temp_val * value) < 1e-5);
            temp_val *= value;
            vect[i] = value;
        }
        // printf("Current val: %lf\n", temp_val);
    }
}

static void genpi(double *a, long size) {
    for (int i = 0; i < size; i++)
    {
        a[i]  = (i + 1.0) / (2.0 * i + 1.0);
        a[i] *= (i + 1.0) / (2.0 * i + 3.0);
        a[i] *= 4.0;
    }
}
static double calc_reference(double *vect, long size) {
    double result = 1;
    for (long i = 0; i < size; ++i) {
        result *= vect[i];
        // printf("S Results: %lf\n", result);
    }
    // printf("Results: %lf\n", result);
    return result;
}

static bool compare_results(double val1, double val2, bool print_pass = false) {
    if (fabs(val1 - val2) < 10e-5) {
        if (print_pass) {
            printf("[PASSED]\n\tReference\t %s = %lf\n \tis equal to\t %s = %lf\n",
                    VAL_NAME(val1), val1, VAL_NAME(val2), val2);
        }
        return true;
    } else {
        printf("[FAILED]\n\tReference\t %s = %lf\n \tnot equal to\t %s = %lf\n",
                    VAL_NAME(val1), val1, VAL_NAME(val2), val2);
        return false;
    }
}
