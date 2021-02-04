#include "sort.h"
#include <stdio.h>

/**
 * heapify - To heapify a subtree rooted with node i
 *
 * @arr: tarray of integers.
 * @n: size of the array.
 * @i: index for node.
 * @size: the size again but in size_t format.
 *
 * Return: Nothing.
 */
void heapify(int arr[], int n, size_t size, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		print_array(arr, size);
		heapify(arr, n, size, largest);
	}
}
/**
 * heap_sort - main function to do heap sort.
 *
 * @arr: array of int to sort.
 * @n: size of the array.
 *
 * Return: Nothing.
 */
void heap_sort(int arr[], size_t n)
{
	int i;

	if (!arr)
		return;
	for (i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, n, i);

	for (i = n - 1; i > 0; i--)
	{

		swap(&arr[0], &arr[i]);
		print_array(arr, n);
		heapify(arr, i, n, 0);
	}
	swap(&arr[0], &arr[i]);
	heapify(arr, i, n, 0);
}
/**
 * swap - swaps variables by reference.
 *
 * @a: a pointer to int.
 * @b: a pointer to int.
 *
 * Return: Nothing.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
