#include "sort.h"

/**
 * isSorted - check if the array is sorted
 * @array: array to be sorted contains only numbers >= 0
 * @size: array size
 * Return: nothing
 */
int isSorted(int *array, size_t size)
{
    size_t i;
	for (i = 0; i < size - 1; i++)
	{
		if (array[i] > array[i + 1])
		return (0);
	}
	return (1);
}

/**
 * radix_sort - sorts an array of integers in ascending
 * ***********  order using the LSD Radix sort algorithm
 * @array: array to be sorted contains only numbers >= 0
 * @size: array size
 * Return: nothing
 */
void radix_sort(int *array, size_t size)
{
	int i, j, tmp, min;
	int count;
	int dev = 10;

    count = size;
	if (!array || size == 0)
		return;

	while (!isSorted(array, size))
	{
		for (i = 0; i < count; i++)
		{
			int k = i;

			min = array[i] % dev;

			/* To find minimum LSD */

			for (j = i + 1; j < count; j++)
			{
				if (min > (array[j] % dev))
				{
					min = array[j] % dev;
					k = j;
				}
			}

			tmp = array[k];
			array[k] = array[i];
			array[i] = tmp;
		}

		print_array(array, size);
		dev *= 10;
	}

}