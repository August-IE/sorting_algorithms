#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * 
 * @a: A pointer to the first node to swap.
 * @b: The second node to swap.
 */
void swap_nodes(listint_t *a, listint_t *b)
{
	if (a->prev != NULL)
		a->prev->next = b;
	if (b->next != NULL)
		b->next->prev = a;
    a->next = b->next;
    b->prev = a->prev;
    a->prev =b;
    b->next = a;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iterate, *insert;

	if (!list || !*list || !(*list)->next)
    return;

    iterate = (*list)->next;
    while (1)
	{
        insert = iterate;
        iterate = iterate->next;
        while (insert && insert->prev)
		{
            if (insert->prev->n > insert->n)
            {
                swap_nodes(insert->prev, insert);
                if (!insert->prev)
                *list = insert;
                print_list((const listint_t *)*list);
            }
            else
            insert = insert->prev;
        }
	}
}
