//
// Created by Michal Ziobro on 31/07/2016.
//

#ifndef COLLECTIONS_COMPARER_H
#define COLLECTIONS_COMPARER_H

#include <stdio.h>

typedef int (*compare_int_func_t)(const int, const int);
typedef int (*compare_func_t)(const void *, const void *);
typedef int (*compare_array_func_t)(const void *, const void*, const size_t);

int int_cmp_func(const int a, const int b);
int int_ptr_cmp_func(const void *i1, const void *i2);
int float_cmp_func(const float a, const float b);
int float_ptr_cmp_func(const void *f1, const void * f2);
int str_cmp_func(const void *str1, const void *str2);
int pthread_cmp_func(const void *pthread1, const void *pthread2);
int binary_cmp_func(const void *bin1, const void *bin2, const size_t len);

#endif //COLLECTIONS_COMPARER_H
