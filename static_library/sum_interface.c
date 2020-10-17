#include "../include/sum_interface.h"

//void sum_of_even(const int *array, size_t size) {
//
//}
//
//void sum_of_odd(const int *array, size_t size) {
//    long long result = 0;
//    for (size_t i = 1; i < size; i += 2)
//        result += array[i];
//    return result;
//}

int set_sum(const int *array, size_t size, long long* even_sum, long long* odd_sum) {
    *even_sum = *odd_sum = 0;
    for (size_t i = 0; i < size; i++)
        if (array[i] % 2 == 0)
            *even_sum += array[i];
        else
            *odd_sum += array[i];
    return SUCCESS;
}
