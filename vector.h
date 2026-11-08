#pragma once
#define C_VECTOR_H
#include <stdlib.h>

typedef struct {
    void** data;
    size_t size;
} Vector;

void vector_init(Vector** vec) {
	*vec = (Vector*)malloc(sizeof(Vector));
	if (*vec != NULL) {
		(*vec)->data = NULL;
		(*vec)->size = 0;
	}
}

void vector_free(Vector* vec) {
	free(vec->data);
	free(vec);
}
void vector_push_back(Vector* vec, void* value) {
	vec->data = (void**)realloc(vec->data, (vec->size + 1) * sizeof(void*));
	vec->data[vec->size] = value;
	vec->size++;
}
void vector_pop_back(Vector* vec) {
	if (vec->size > 0) {
		vec->size--;
		vec->data = (void**)realloc(vec->data, vec->size * sizeof(void*));
	}
}
void vector_set(Vector* vec, size_t index, void* value) {
	vec->data[index] = value;
}
void* vector_get(Vector* vec, size_t index) {
	return vec->data[index];
}