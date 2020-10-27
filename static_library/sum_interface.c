#include "../include/sum_interface.h"

int find_sum_static(const int *array, size_t size, long long* even_sum, long long* odd_sum) {
    if (!array || !even_sum || !odd_sum)
        return 0;
    *even_sum = *odd_sum = 0;
    for (size_t i = 0; i < size; i++)
        if (array[i] % 2 == 0)
            *even_sum += array[i];
        else
            *odd_sum += array[i];
    return SUCCESS;
}
