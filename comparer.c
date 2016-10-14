//
// Created by Michal Ziobro on 31/07/2016.
//

#include <string.h>
#include <pthread.h>

int int_cmp_func(const int a, const int b) {
    return (a < b) ? -1 : (a > b);
}

int int_ptr_cmp_func(const void *int1, const void *int2) {

    const int *i1 = (const int *) int1;
    const int *i2 = (const int *) int2;

    return (*i1 < *i2) ? -1 : (*i1 > *i2);
}

int float_cmp_func(const float a, const float b) {
    return (a < b) ? -1 : (a > b);
}

int float_ptr_cmp_func(const void *float1, const void * float2) {

    const float *f1 = (const float *) float1;
    const float *f2 = (const float *) float2;

    return (*f1 < *f2) ? -1 : (*f1 > *f2);
}

int str_cmp_func(const void *str1, const void *str2) {
    return strcmp((const char *) str1, (const char *) str2);
}

int pthread_cmp_func(const void *pthread1, const void *pthread2) {

    pthread_t p1 = (pthread_t) pthread1;
    pthread_t p2 = (pthread_t) pthread2;
    // pthread_equal() returns 0 if thread IDs don't match, and non-zero value if they match
    return !pthread_equal(p1, p2);
}