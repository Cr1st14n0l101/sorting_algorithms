#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
*/

void counting_sort(int *array, size_t size)
{
	int *tmp = NULL, *new = NULL;
	size_t i;

	tmp = malloc(sizeof(int) * 100);
	if (!tmp)
		return;
	new = malloc(sizeof(int) * size);
	if (!new)
	{
		free(tmp);
		return;
	}
	for (i = 0; i < 100; i++)
		tmp[i] = 0;
	for (i = 0; i < size; i++)
		tmp[array[i]]++;
	for (i = 1; i < 100; i++)
		tmp[i] += tmp[i - 1];
	print_array(tmp, 100);
	for (i = 0; i < size; i++)
	{
		new[tmp[array[i]] - 1] = array[i];
		tmp[array[i]]--;
	}
	for (i = 0; i < size; i++)
	{
		array[i] = new[i];
	}
}
