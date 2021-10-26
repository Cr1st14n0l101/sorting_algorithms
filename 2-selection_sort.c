#include "sort.h"

/**
 * swap - change the values of two variables
 * @array: is an array os integers
 * @size: is the size of the array
 * @a: the first integer
 * @b: the second integer
 * Return: Void
 */
void swap(int *array, size_t size, int *a, int *b)
{
	int t = *a;

	if (*a != *b)
	{
		*a = *b;
		*b = t;
		print_array((const int *)array, size);
	}
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm.
 * @array: Array of integers.
 * @size: Size of array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j;

	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (array[i] < array[j])
				swap(array, size, &array[i], &array[j]);
			else
				j++;
		}
		i++;
	}
}
