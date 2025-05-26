#include <stdlib.h>
#include <stdio.h>
#include "dynamic_array.h"

void InitArray(DynamicArray *arr, size_t initialCapacity)
{
  arr->data = malloc(initialCapacity * sizeof(int));
  arr->size = 0;
  arr->capacity = initialCapacity;
  if (arr->data == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
}

void Append(DynamicArray *arr, int value)
{
  if (arr->size == arr->capacity)
  {
    arr->capacity *= 2;
    int *temp = realloc(arr->data, arr->capacity * sizeof(int));
    if (temp == NULL)
    {
      fprintf(stderr, "Memory reallocation failed\n");
      exit(EXIT_FAILURE);
    }
    arr->data = temp;
  }
  arr->data[arr->size++] = value;
}

void FreeArray(DynamicArray *arr)
{
  free(arr->data);
  arr->data = NULL;
  arr->size = arr->capacity = 0;
}