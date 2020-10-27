#include "gtest/gtest.h"

extern "C" {
#include "../include/sum_interface.h"
}

TEST(comparison, test1) {
    size_t size = 10;
    int* array = get_array(size);
    long long even_static, odd_static, even_dynamic, odd_dynamic;
    find_sum_static(array, size, &even_static, &odd_static);
    find_sum_dynamic(array, size, &even_dynamic, &odd_dynamic);
    ASSERT_EQ(even_static, even_dynamic);
    ASSERT_EQ(odd_static, odd_dynamic);
    free_array(array);
}

TEST(comparison, test2) {
    size_t size = 96769;
    int* array = get_array(size);
    long long even_static, odd_static, even_dynamic, odd_dynamic;
    find_sum_static(array, size, &even_static, &odd_static);
    find_sum_dynamic(array, size, &even_dynamic, &odd_dynamic);
    ASSERT_EQ(even_static, even_dynamic);
    ASSERT_EQ(odd_static, odd_dynamic);
    free_array(array);
}

TEST(comparison, stress_test1) {
    size_t size;
    char filename[] = "../unit_tests/stress_data/stressTest1.txt";
    int* array = get_array_from_file(filename, &size);
    if (!array)
        return;
    long long even_static, odd_static, even_dynamic, odd_dynamic;
    find_sum_static(array, size, &even_static, &odd_static);
    find_sum_dynamic(array, size, &even_dynamic, &odd_dynamic);
    ASSERT_EQ(even_static, even_dynamic);
    ASSERT_EQ(odd_static, odd_dynamic);
    free_array(array);
}

TEST(comparison, stress_test2) {
    size_t size;
    char filename[] = "../unit_tests/stress_data/stressTest2.txt";
    int* array = get_array_from_file(filename, &size);
    if (!array)
        return;
    long long even_static, odd_static, even_dynamic, odd_dynamic;
    find_sum_static(array, size, &even_static, &odd_static);
    find_sum_dynamic(array, size, &even_dynamic, &odd_dynamic);
    ASSERT_EQ(even_static, even_dynamic);
    ASSERT_EQ(odd_static, odd_dynamic);
    free_array(array);
}

