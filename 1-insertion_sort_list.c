#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: Doubly linked list of integers.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *new, *bubble;

	if (!list || !*list || !(*list)->next)
		return;

	tmp = new = (*list)->next;
	while (new)
	{
		tmp = new;
		new = new->next;
		bubble = tmp->prev;
		while (bubble && bubble->n > tmp->n)
		{
			bubble->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = bubble;

			if (bubble->prev)
				bubble->prev->next = tmp;
			else
				*list = tmp;

			tmp->prev = bubble->prev;
			tmp->next = bubble;
			bubble->prev = tmp;
			bubble = tmp->prev;
			print_list(*list);
		}
	}
}
