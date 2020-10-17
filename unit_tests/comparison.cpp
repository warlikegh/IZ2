#include "gtest/gtest.h"

extern "C" {
#include "../include/sum_interface.h"
}

void read_from_file(const char* filename, long long* even1, long long* odd1, long long* even2, long long* odd2) {
    FILE* file = fopen(filename, "r");
    if (!file)
        return;
    fscanf(file, "%lld %lld %lld %lld", even1, odd1, even2, odd2);
    fclose(file);
}


TEST(comparison, test1) {
    long long even1, odd1, even2, odd2;
    read_from_file("../unit_tests/results/test1", &even1, &odd1, &even2, &odd2);
    ASSERT_EQ(even1, even2);
    ASSERT_EQ(odd1, odd2);
}

TEST(comparison, test2) {
    long long even1, odd1, even2, odd2;
    read_from_file("../unit_tests/results/test2", &even1, &odd1, &even2, &odd2);
    ASSERT_EQ(even1, even2);
    ASSERT_EQ(odd1, odd2);
}

TEST(comparison, stress_test1) {
    long long even1, odd1, even2, odd2;
    read_from_file("../unit_tests/results/stress_test1", &even1, &odd1, &even2, &odd2);
    ASSERT_EQ(even1, even2);
    ASSERT_EQ(odd1, odd2);
}

TEST(comparison, stress_test2) {
    long long even1, odd1, even2, odd2;
    read_from_file("../unit_tests/results/stress_test2", &even1, &odd1, &even2, &odd2);
    ASSERT_EQ(even1, even2);
    ASSERT_EQ(odd1, odd2);
}

