#ifndef __SORT_H__
#define __SORT_H__
#include <stdlib.h>
void heapify(int arr[], int n, size_t size, int i);
void heap_sort(int arr[], size_t n);
void print_array(const int *array, size_t size);
void swap(int *a, int *b);
#endif
