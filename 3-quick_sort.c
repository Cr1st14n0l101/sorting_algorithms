#include "sort.h"

/**
 * quick_sort - sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: is an array of integers
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;

	_qsort(array, size, 0, size - 1);
}

/**
 * _qsort - quicksort with Lomuto partitioning
 * @array: is an array of integers
 * @size: size of the array
 * @low: the low index of the sort range
 * @hight: the high index of the sort range
 * Return: void
 */
void _qsort(int *array, size_t size, ssize_t low, ssize_t hight)
{
	if (low < hight)
	{
		size_t pivot = to_lomuto(array, size, low, hight);

		_qsort(array, size, low, pivot - 1);
		_qsort(array, size, pivot + 1, hight);
	}
}

/**
 * to_lomuto - returns the lomuto partition for the pivot of quicksort
 * @array: is an array os integers
 * @size: is the size of the array
 * @low: the position lower in the array
 * @hight: the position highter on the array
 * Return: the lomuto partition
 */
size_t to_lomuto(int *array, size_t size, ssize_t low, ssize_t hight)
{
	int i, j;
	int pivot = array[hight];

	for (i = j = low; j <= hight; j++)
		if (array[j] < pivot)
			swap(array, size, &array[i++], &array[j]);
	swap(array, size, &array[i], &array[hight]);

	return (i);
}

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
