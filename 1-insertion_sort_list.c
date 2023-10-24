#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @x: A pointer to the first node to swap.
 * @y: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **x, listint_t *y)
{
	(*x)->next = y->next;
	if (y->next != NULL)
		y->next->prev = *x;
	y->prev = (*x)->prev;
	y->next = *x;
	if ((*x)->prev != NULL)
		(*x)->prev->next = y;
	else
		*h = y;
	(*x)->prev = y;
	*x = y->prev;
}
/**
 * insertion_sort_list - A function that sorts a doubly linked list of integers
 * in ascending order using the insertion sort algorithm.
 *
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iterate, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iterate = (*list)->next; iterate != NULL; iterate = tmp)
	{
		tmp = iterate->next;
		insert = iterate->prev;
		while (insert != NULL && iterate->n < insert->n)
		{
			swap_nodes(list, &insert, iterate);
			print_list((const listint_t *)*list);
		}
	}
}
