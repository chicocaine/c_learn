#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>

typedef struct{
  int *data;
  size_t size;
  size_t capacity;
} DynamicArray;


void InitArray(DynamicArray *arr, size_t initialCapacity);
void Append(DynamicArray *arr, int value);
void FreeArray(DynamicArray *arr);

#endif