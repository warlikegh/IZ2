#include <stdio.h>
#include "../include/sum_interface.h"

int* get_array(size_t size) {
    int* array = calloc(size, sizeof(int));
    if (!array)
        return NULL;
    for (int i = 0; i < size; i++)
        array[i] = i % 100;
    return array;
}

static size_t get_size_from_file(char* filename) {
    size_t size = 0;
    int temp;
    FILE* file = fopen(filename, "rb");
    if (!file)
        return 0;
    while (!feof(file)) {
        if (fscanf(file, "%d", &temp) == 1) {
            size++;
        }
    }
    fclose(file);
    return size;
}

int* get_array_from_file(char* filename, size_t* size) {
    if (!filename || !size)
        return NULL;
    *size = get_size_from_file(filename);
    FILE* file = fopen(filename, "rb");
    if (!file)
        return NULL;
    int* array = calloc(*size, sizeof(int));
    if (!array) {
        fclose(file);
        return NULL;
    }
    int i = 0;
    while (!feof(file)) {
        if (fscanf(file, "%d", &array[i]) == 1) {
            i++;
        }
    }
    fclose(file);
    return array;
}

void free_array(int* array) {
    if (!array)
        return;
    free(array);
}
