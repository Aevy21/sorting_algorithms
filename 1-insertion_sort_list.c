#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void insertion_sort_list(listint_t **list);
/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order using
 *                       the insertion sort algorithm.
 * @list: Pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *back, *next_node, *temp;
	int swap_count;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		swap_count = 0; /* Initialize swap count for each outer loop iteration */

		back = current->prev;
		next_node = current->next;

		while (back && back->n > current->n)
		{
			back->next = next_node;

			if (next_node != NULL)
				next_node->prev = back;

			current->next = back;
			current->prev = back->prev;

			if (back->prev != NULL)
				back->prev->next = current;
			else
				*list = current; /* Update the head if needed */

			back->prev = current;

			/* Correct the next_node pointer */
			temp = back;
			back = current->prev;
			next_node = temp;

			/* Traverse result list and compare every node with our current node. */
			swap_count++;
		}

		/* If any swaps , print the list after the inner loop */
		if (swap_count > 0)
		{
			print_list(*list);
		}

		current = next_node; /* Move to the next element in the list */
	}
}

