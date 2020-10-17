include_directories("${PROJECT_SOURCE_DIR}/include")

set(sources "${PROJECT_SOURCE_DIR}/unit_tests/main.cpp"
        "${PROJECT_SOURCE_DIR}/array_utils/array_functions.c")

add_executable(single_tests "${PROJECT_SOURCE_DIR}/static_library/sum_interface.c"
        "${PROJECT_SOURCE_DIR}/unit_tests/single.cpp" ${sources})
target_link_libraries(single_tests gtest_main static)
add_test(NAME single COMMAND single_tests)

add_executable(multi_tests "${PROJECT_SOURCE_DIR}/dynamic_library/sum_interface.c"
        "${PROJECT_SOURCE_DIR}/unit_tests/multi.cpp" ${sources})
target_link_libraries(multi_tests gtest_main dynamic)
add_test(NAME multi COMMAND multi_tests)

add_executable(comparison_tests "${PROJECT_SOURCE_DIR}/unit_tests/comparison.cpp" ${sources})
target_link_libraries(comparison_tests gtest_main)
add_test(NAME comparison COMMAND comparison_tests)