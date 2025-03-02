#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

size_t size_from_type(VEC_TYPE type) {
    switch (type)
    {
        case TYPE_INT:
            return sizeof(int);
        case TYPE_DOUBLE:
            return sizeof(double);
        default:
            printf("PANIC!!! Reached Unknown Vec Type\n");
            return sizeof(uint8_t);
    }
}

void print_type(Vec *vector, size_t index, void *data) {
    switch (vector->data_type)
    {
        case TYPE_INT:
            printf("Index = %ld, Val = %d\n", index, *((int*)data));
            break;
        case TYPE_DOUBLE:
            printf("Index = %ld, Val = %.2f\n", index, *((double*)data));
            break;
        default:
            printf("PANIC!!! Reached Unknown Vec Type\n");
            break;
    }
}

/// @brief Initialize a vector with a given initial size
/// @param initial_size 
/// @return 
Vec* init_vec(size_t initial_size, VEC_TYPE type) {

    Vec *vector = malloc(sizeof(Vec));

    // The vector pointer in memory
    const size_t type_size = size_from_type(type);

    vector->size = initial_size;
    vector->type_size = type_size;
    printf("ASSIGNED TYPE SIZE = %ld\n", type_size);
    vector->capacity = initial_size * type_size;
    vector->data_type = type;
    vector->data = malloc(vector->capacity);

    memset(vector->data, 0, vector->capacity);

    return vector;
}

void print_vec(Vec *vector) {
    if (vector->size == 0)
    {
        printf("Vector is Empty\n");
        return;
    }


    void* current;
    for (size_t i = 0; i < vector->size; i++)
    {
        current = (char*) vector->data + i * vector->type_size;
        print_type(vector, i, current);
    }
}

void print_head(Vec *vector) {
    printf("Head = %p\n", vector->data);
}

void resize_vec(Vec *vector) {
    size_t added_capacity = vector->capacity;
    vector->capacity *= 2;
    vector->data = realloc(vector->data, vector->capacity);
    void *newdata = (char*) vector->data + added_capacity * vector->type_size;
    memset(newdata, 0, added_capacity);
}

void append_vec(Vec *vector, void *element) {
    //Expand Vector
    size_t new_size = vector->size + 1;
    if (new_size * vector->type_size > vector->capacity)
    {
        resize_vec(vector);
    }

    void *destination = (char*)vector->data + vector->size * vector->type_size;

    memcpy(destination, element, vector->type_size);
    vector->size = new_size;
}

/// @brief Given an existing vector, append an element to 
///        the end of the list.
/// @param vector 
/// @param element 
void append_veci(Vec *vector, int element) {
    if (vector->data_type != TYPE_INT)
    {
        printf("Can't Append int to non-int vector");
        return;
    }
    append_vec(vector, (void*) &element);
}

void append_vecd(Vec *vector, double element) {
    if (vector->data_type != TYPE_DOUBLE)
    {
        printf("Can't Append double to non-double vector");
        return;
    }
    
    append_vec(vector, (void*) &element);
}

/// @brief Given an existing vector, insert an element at 
///        the given index.
/// @param vector 
/// @param index   index to insert at. Insert at index 2 moves
///                element two and beyond over by 1 index
/// @param element value to insert 
void insert_vec(Vec *vector, size_t index, void* element) {
    if (index >= vector->size)
    {
        printf("Insert Vec out of bounds, appending instead\n");
        append_vec(vector, element);
        return;
    }

    size_t new_size = vector->size + 1;
    if (new_size * vector->type_size >= vector->capacity)
    {
        resize_vec(vector);
    }
    vector->size += 1;
    
    void *curr, *prev;
    for (size_t i = new_size; i > index; i--)
    {
        curr = (char*) vector->data + i * vector->type_size;
        prev = (char*) vector->data + (i - 1) * vector->type_size;

        memcpy(curr, prev, vector->type_size);
    }

    curr = (char*) vector->data + index * vector->type_size;
    memcpy(curr, element, vector->type_size);
}

void* pop_front(Vec *vector) {

    if (vector == NULL || vector->size == 0)
    {
        printf("Cannot pop empty vector\n");
        return NULL;
    }
    
    void* data = malloc(vector->type_size);
    memcpy(data, vector->data, vector->type_size);
    vector->data = (char*)vector->data + vector->type_size;
    vector->size -= 1;
    return data;
}

/// @brief Given a valid vector with elements, remove the first
///        element in the list and return a reference to it.
/// @param vector 
/// @return The removed value as a pointer
int* pop_fronti(Vec *vector) {

    if (vector == NULL || vector->size == 0)
    {
        printf("Cannot pop empty vector");
        return NULL;
    }
    void* data = pop_front(vector);
    return (int*) data;
}

/// @brief Given a valid vector with elements, retrieve the first
///        element in the list and return a reference to it.
/// @param vector 
/// @return The first value as a pointer
int* peek_front(Vec *vector) {

    // if (vector == NULL || vector->size == 0)
    // {
    //     printf("Cannot pop empty vector");
    //     return NULL;
    // }
    // return vector->data;
    return NULL;
}

void free_vec(Vec *vector) {
    free(vector);
}