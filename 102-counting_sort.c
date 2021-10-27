#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
*/

void counting_sort(int *array, size_t size)
{
	int *tmp = NULL, *new = NULL, i, max = array[0];

	if (!array || size <= 1)
		return;

	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	max++;
	tmp = malloc(sizeof(int) * max);
	if (!tmp)
		return;
	new = malloc(sizeof(int) * size);
	if (!new)
	{
		free(tmp);
		return;
	}
	for (i = 0; i < max; i++)
		tmp[i] = 0;
	for (i = 0; i < (int)size; i++)
		tmp[array[i]]++;
	for (i = 1; i < max; i++)
		tmp[i] += tmp[i - 1];
	print_array(tmp, max);
	for (i = 0; i < (int)size; i++)
	{
		new[tmp[array[i]] - 1] = array[i];
		tmp[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
	{
		array[i] = new[i];
	}
	free(tmp);
	free(new);
}
