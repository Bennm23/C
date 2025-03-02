#ifndef VECTOR_H
#define VECTOR_H

#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

typedef enum {

    TYPE_INT,
    TYPE_DOUBLE,

} VEC_TYPE;

typedef struct {

    size_t size;
    size_t type_size;
    size_t capacity;
    void* data;
    VEC_TYPE data_type;

} Vec;


size_t size_from_type(VEC_TYPE type);

void print_type(Vec *vector, size_t index, void *data);

Vec* init_vec(size_t initial_size, VEC_TYPE type);

void print_vec(Vec *vector);
void print_head(Vec *vector);

void resize_vec(Vec *vector);

void append_vec(Vec *vector, void *element);
void append_veci(Vec *vector, int element);
void append_vecd(Vec *vector, double element);
void insert_vec(Vec *vector, size_t index, void* element);

void* pop_front(Vec *vector);
int* pop_fronti(Vec *vector);
int* peek_front(Vec *vector);

void free_vec(Vec *vector);

#endif