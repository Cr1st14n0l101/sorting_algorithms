#ifndef _SORTING_ALGORITHMS
#define _SORTING_ALGORITHMS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*helper functions*/
void print_list(const listint_t  *list);
void print_array(const int *array, size_t size);

/*functions*/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void _qsort(int *array, size_t size, ssize_t low, ssize_t hight);
size_t to_lomuto(int *array, size_t size, ssize_t low, ssize_t hight);
void swap(int *array, size_t size, int *a, int *b);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);

#endif
