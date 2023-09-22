#include <stdio.h>
#include "lists.h"

/**
 * print_list - Prints all elements of a list_t list.
 * @h: A pointer to the head of the linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_list(const list_t *h)
{
	size_t node_count = 0; /* Initialize the node count to 0 */

	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", h->len, h->str);

		h = h->next; /* Move to the next node */
		node_count++; /* Increment the node count */
	}

	return (node_count);
}

