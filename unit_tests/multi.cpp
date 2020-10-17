#include "gtest/gtest.h"

extern "C" {
#include "../include/sum_interface.h"
}

TEST(multi_process, test1) {
    int* array = get_array(10);
    long long even, odd;
    set_sum(array, 10, &even, &odd);
    ASSERT_EQ(even, 20);
    ASSERT_EQ(odd, 25);
    write_to_file("../unit_tests/results/test1", even, odd);
    free_array(array);
}

TEST(multi_process, test2) {
    int* array = get_array(100);
    long long even, odd;
    set_sum(array, 100, &even, &odd);
    ASSERT_EQ(even, 2450);
    ASSERT_EQ(odd, 2500);
    write_to_file("../unit_tests/results/test2", even, odd);
    free_array(array);
}

TEST(multi_process, stress_test1) {
    size_t size;
    char filename[] = "../unit_tests/stress_data/stressTest1.txt";
    int* array = get_array_from_file(filename, &size);
    long long even, odd;
    set_sum(array, size, &even, &odd);
    write_to_file("../unit_tests/results/stress_test1", even, odd);
    free_array(array);
}

TEST(multi_process, stress_test2) {
    size_t size;
    char filename[] = "../unit_tests/stress_data/stressTest2.txt";
    int* array = get_array_from_file(filename, &size);
    long long even, odd;
    set_sum(array, size, &even, &odd);
    write_to_file("../unit_tests/results/stress_test2", even, odd);
    free_array(array);
}
