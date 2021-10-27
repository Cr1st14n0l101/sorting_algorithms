#include "sort.h"


/**
 * divide_array - Divides the array in a recursive way.
 * @array: Array to sort.
 * @tmp: Copy of the original array.
 * @size: Array's size.
 */
void divide_array(int *array, int *tmp, size_t size)
{
	int size_l, size_r;

	if (size == 1)
		return;

	size_l = size / 2;
	size_r = size - size_l;

	divide_array(array, tmp, size_l);
	divide_array(array, tmp + size_l, size_r);

	merge_array(array, tmp, size_l, size_r);
}

/**
 * merge_array - Sort two adjacents int arrays in memory
 * @array: Array to sort.
 * @tmp_l: Pointer to the left array to be sorted.
 * @size_l: Left array's size.
 * @size_r: Right array's size.
 */
void merge_array(int *array, int *tmp_l, size_t size_l, size_t size_r)
{
	int *tmp_r = NULL;
	unsigned int i, j;

	tmp_r = tmp_l + size_l;
	printf("Merging...\n");
	printf("[left]: "), print_array(tmp_l, size_l);
	printf("[right]: "), print_array(tmp_r, size_r);
	i = j = 0;
	while (i < size_l && j < size_r)
	{
		if (tmp_l[i] <= tmp_r[j])
			array[i + j] = tmp_l[i], i++;
		else
			array[i + j] = tmp_r[j], j++;

	}
	while (i < size_l)
	{
		array[i + j] = tmp_l[i];
		i++;
	}
	while (j < size_r)
	{
		array[i + j] = tmp_r[j];
		j++;
	}
	printf("[Done]: ");
	print_array(array, size_l + size_r);

	for (i = 0; i < size_l + size_r; i++)
		tmp_l[i] = array[i];
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;
	size_t i;

	if (!array || size < 1)
		return;

	tmp = malloc(sizeof(*tmp) * size);
	if (!tmp)
		exit(1);

	for (i = 0; i < size; i++)
		tmp[i] = array[i];

	divide_array(array, tmp, size);
	free(tmp);
}
