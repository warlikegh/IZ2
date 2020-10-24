#ifndef IZ2_SUM_INTERFACE_H
#define IZ2_SUM_INTERFACE_H

#include <stdlib.h>

#define SUCCESS 1
#define ERROR 0
#define ERROR_ALLOC -1
#define ERROR_FORK -2
#define ERROR_UNMAP -3

// static_library
int find_sum_static(const int* array, size_t size, long long* even_sum, long long* odd_sum);

// dynamic_library
int find_sum_dynamic(const int* array, size_t size, long long* even_sum, long long* odd_sum);

// array functions
int* get_array(size_t size);

int* get_array_from_file(char* filename, size_t* size);

void free_array(int* array);

#endif //IZ2_SUM_INTERFACE_H
