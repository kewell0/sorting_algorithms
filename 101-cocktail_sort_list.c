#include "sort.h"

/**
 * swap_node - swaps two nodes adjacent to one another
 * @list: pointer to head node of doubly linked list
 * @node: pointer to node to switch with next node
 *
 * Return: no return value (void)
 */
void swap_node(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of ints in ascending order
 * @list: Double pointer to head node of doubly linked list
 *
 * Return: no return value (void)
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *now = NULL;
	int swapped = 1;

	if (list == NULL || *list == NULL)
		return;
	now = *list;
	while (swapped != 0)
	{
		swapped = 0;
		while (now->next != NULL)
		{
			if (now->n > now->next->n)
			{
				swap_node(list, now);
				print_list(*list);
				swapped = 1;
			}
			else
			{
				now = now->next;
			}
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (now->prev != NULL)
		{
			if (now->n < now->prev->n)
			{
				swap_node(list, now->prev);
				print_list(*list);
				swapped = 1;
			}
			else
			{
				now = now->prev;
			}
		}
	}
}
