cmake_minimum_required(VERSION 3.20)
project(dynamic_arrays LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(vector src/vector.c)
target_include_directories(vector PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(test_vector tests/test_vector.c)
target_link_libraries(test_vector PRIVATE vector)

enable_testing()
add_test(NAME vector_tests COMMAND test_vector) 