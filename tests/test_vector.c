
#include <assert.h>
#include <stdio.h>
#include "../include/vector.h"

void test_creation(void) {
    Vector *v = vector_create(4);

    assert(v != NULL);
    assert(v->size == 0);
    assert(v->capacity == 4);

    vector_destroy(v);
}

void test_push(void) {
    Vector *v = vector_create(1);

    vector_push(v, 15);
    vector_push(v, 24);
    assert(v->size == 2);
    assert(v->capacity == 2);

    for (int i = 0; i < 120; i++){
        vector_push(v, i);
    }
    assert(v->size == 122);
    assert(v->capacity == 128);

    vector_destroy(v);
}

void test_zero_capacity_growth(void) {
    Vector *v = vector_create(0);

    assert(v != NULL);
    assert(v->size == 0);
    assert(v->capacity == 0);
    assert(vector_push(v, 42));
    assert(v->size == 1);
    assert(v->capacity == 4);
    assert(v->data[0] == 42);

    vector_destroy(v);
}

void test_pop(void) {
    Vector *v = vector_create(1);
    vector_push(v, 15);
    vector_push(v, 20);
    
    int result;
    assert(vector_pop(v, &result));
    assert(result == 20);
    assert(v->size == 1);
    assert(vector_pop(v, &result));
    assert(result == 15);
    assert(v->size == 0);
    assert(!vector_pop(v, &result));
    vector_destroy(v);
}

void test_set_and_get(void) {
    Vector *v = vector_create(3);
    int result = 0;

    assert(vector_push(v, 10));
    assert(vector_push(v, 20));
    assert(vector_set(v, 1, 25));
    assert(vector_get(v, 1, &result));
    assert(result == 25);

    assert(!vector_set(v, 2, 30));
    assert(!vector_get(v, 2, &result));

    vector_destroy(v);
}

void test_insert(void) {
    Vector *v = vector_create(4);
    int result = 0;

    assert(vector_push(v, 10));
    assert(vector_push(v, 30));
    assert(vector_insert(v, 1, 20));
    assert(v->size == 3);
    assert(vector_get(v, 0, &result) && result == 10);
    assert(vector_get(v, 1, &result) && result == 20);
    assert(vector_get(v, 2, &result) && result == 30);

    assert(vector_insert(v, 3, 40));
    assert(v->size == 4);
    assert(vector_get(v, 3, &result) && result == 40);
    assert(!vector_insert(v, 5, 40));
    vector_destroy(v);
}

void test_remove(void) {
    Vector *v = vector_create(4);
    int result = 0;

    assert(vector_push(v, 10));
    assert(vector_push(v, 20));
    assert(vector_push(v, 30));
    assert(vector_remove(v, 1));
    assert(v->size == 2);
    assert(vector_get(v, 0, &result) && result == 10);
    assert(vector_get(v, 1, &result) && result == 30);

    assert(vector_remove(v, 0));
    assert(v->size == 1);
    assert(vector_get(v, 0, &result) && result == 30);
    assert(!vector_remove(v, v->size));
    vector_destroy(v);
}

void test_reserve_and_clear(void) {
    Vector *v = vector_create(2);

    assert(vector_reserve(v, 8));
    assert(v->capacity >= 8);
    assert(vector_push(v, 10));
    assert(vector_push(v, 20));
    assert(v->size == 2);

    vector_clear(v);
    assert(v->size == 0);
    assert(v->capacity >= 8);
    assert(vector_push(v, 30));
    assert(v->size == 1);
    assert(vector_reserve(v, 1));
    assert(v->capacity >= 8);

    vector_destroy(v);
}

int main() {
    test_creation();
    test_push();
    test_zero_capacity_growth();
    test_pop();
    test_set_and_get();
    test_insert();
    test_remove();
    test_reserve_and_clear();
    puts("All tests passed");
    return 0;
}
