#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdbool.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

Vector *vector_create(size_t initial_capacity);
void vector_destroy(Vector *v);
bool vector_push(Vector *v, int value);
bool vector_pop(Vector *v, int *out);
bool vector_set(Vector *v, size_t index, int value);
bool vector_get(Vector *v, size_t index, int *out);
bool vector_insert(Vector *v, size_t index, int value);
bool vector_remove(Vector *v, size_t index);
bool vector_reserve(Vector *v, size_t desired_capacity);
void vector_clear(Vector *v);

#endif