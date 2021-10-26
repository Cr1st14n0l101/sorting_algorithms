#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending
 * order using the Shell sort algorithm
 * @array: is an array of integers
 * @size: size of the array
 * Return: Void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, n, gap;
	int tmp;

	if (!array || !size)
		return;

	n = 1;
	while (n < size)
		n = n * 3 + 1;
	gap = (n - 1) / 3;

	for (; gap; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
