#include "sort.h"

/**
 * selection_sort - Selection sort implementation.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int bubble;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
			if (array[min] > array[j])
				min = j;
		if (min != i)
		{
			bubble = array[i];
			array[i] = array[min];
			array[min] = bubble;
			print_array(array, size);
		}
	}
}
