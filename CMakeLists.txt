cmake_minimum_required(VERSION 3.9)
project(IZ2 C)
enable_language(C CXX)
set(CMAKE_C_FLAGS "-std=c11 -Wall -Werror -Wpedantic")
set(CMAKE_C_STANDARD 99)

set(SRC_MAIN ${PROJECT_SOURCE_DIR}/src/main.c)
set(SRC_FILES_STATIC ${PROJECT_SOURCE_DIR}/static_library/sum_interface.c
        ${PROJECT_SOURCE_DIR}/array_utils/array_functions.c)
set(SRC_FILES_DYNAMIC ${PROJECT_SOURCE_DIR}/dynamic_library/sum_interface.c
        ${PROJECT_SOURCE_DIR}/array_utils/array_functions.c)

include_directories("${PROJECT_SOURCE_DIR}/include")

add_library(sum_static STATIC ${SRC_FILES_STATIC})
add_library(sum_dynamic SHARED ${SRC_FILES_DYNAMIC})

add_executable(IZ2 ${SRC_MAIN})

target_link_libraries(IZ2 sum_static sum_dynamic)

configure_file(CMakeLists.txt.in
        googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build)

enable_testing()
add_subdirectory(unit_tests)
