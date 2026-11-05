# Dynamic Array in C

A small C implementation of a growable array of `int` values. The project is
set up with CMake and includes a CTest test suite.

## Features

- Create and destroy vectors
- Push and pop values
- Read and replace values by index
- Insert and remove values by index
- Reserve capacity and clear contents
- Automatic capacity growth when more space is needed

## Build and test

Requirements: a C17 compiler and CMake 3.20 or newer.

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure
```

## Debug with GDB

Build the debug configuration above, then start the test executable:

```sh
gdb ./build/test_vector
```

For example, stop whenever an item is pushed:

```gdb
break vector_push
run
print v->size
print v->capacity
print value
```

## Project layout

```text
include/vector.h    Public Vector API
src/vector.c        Implementation
tests/test_vector.c Unit tests
CMakeLists.txt      Build and test configuration
```
