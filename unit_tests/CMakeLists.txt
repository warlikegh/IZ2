include_directories("${PROJECT_SOURCE_DIR}/include")

set(sources "${PROJECT_SOURCE_DIR}/unit_tests/main.cpp"
        "${PROJECT_SOURCE_DIR}/unit_tests/comparison.cpp")

add_executable(comparison_tests ${sources})
target_link_libraries(comparison_tests gtest_main sum_static sum_dynamic)
add_test(NAME comparison COMMAND comparison_tests)