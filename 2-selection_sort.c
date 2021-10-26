#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm.
 * @array: Array of integers.
 * @size: Size of array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int bubble;

	if (!array || size <= 0)
		return;

	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				bubble = array[i];
				array[i] = array[j];
				array[j] = bubble;
				j++;
			}
			else
				j++;
		}
		print_array((const int *)array, size);
		i++;
	}
}
