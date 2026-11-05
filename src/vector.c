#include <stdlib.h>
#include <stdint.h>
#include "../include/vector.h"

Vector *vector_create(size_t initial_capacity) {
    Vector *v = malloc(sizeof(Vector));
    if (v == NULL) {
        free(v);
        return NULL;
    }
    v->data = malloc(sizeof(int) * initial_capacity);
    if (v->data == NULL) {
        free(v->data);
        free(v);
        return NULL;
    }
    v->size = 0;
    v->capacity = initial_capacity;

    return v;
}

void vector_destroy(Vector *v) {
    free(v->data);
    free(v);
}

bool vector_push(Vector *v, int value) {
    if (!vector_reserve(v, v->size + 1)){
        return false;
    }
    *(v->data + v->size) = value;
    v->size++;
    return true;
}

bool vector_pop(Vector *v, int *out) {
    if (v->size == 0) {
        return false;
    }
    *out = v->data[v->size - 1];
    v->size--;
    return true;
}

bool vector_set(Vector *v, size_t index, int value) {
    if (index >= v->size) {
        return false;
    }
    v->data[index] = value;
    return true;
}

bool vector_get(Vector *v, size_t index, int *out) {
    if (index >= v->size) {
        return false;
    } 
    *out = v->data[index];
    return true;
}

bool vector_insert(Vector *v, size_t index, int value) {
    if (index > v->size) {
        return false;
    }
    if (!vector_reserve(v, v->size + 1)) {
        return false;
    }
    for (size_t i = v->size; i > index; i--) {
        v->data[i] = v->data[i - 1];
    }
    v->data[index] = value;
    v->size++;
    return true;
}

bool vector_remove(Vector *v, size_t index) {
    if (index >= v->size) {
        return false;
    }
    for (size_t i = index; i < v->size - 1; i++) {
        v->data[i] = v->data[i + 1];
    }
    v->size--;
    return true;
}

bool vector_reserve(Vector *v, size_t desired_capacity) {
    if (v->capacity >= desired_capacity) {
        return true;
    }
    size_t new_capacity = v->capacity;
    if (v->capacity == 0) {
        new_capacity = 4;
    }
    while (new_capacity < desired_capacity) {
        new_capacity *= 2;
    }
    int *tmp = realloc(v->data, new_capacity * sizeof(v->data[0]));
    if (tmp == NULL){
        return false;
    }
    v->data = tmp;
    v->capacity = new_capacity;
    return true;
}

void vector_clear(Vector *v) {
    v->size = 0;
}