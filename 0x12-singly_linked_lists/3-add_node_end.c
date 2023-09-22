#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - Appends a new node to the end of a linked list.
 * @list_head: Double pointer to the list_t list.
 * @new_str: String to be placed in the new node.
 *
 * Return: Address of the new element, or NULL if it fails.
 */
list_t *add_node_end(list_t **list_head, const char *new_str)
{
	size_t str_length = 0;
	list_t *new_node, *temp = *list_head;

	while (new_str[str_length])
		str_length++;

	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(new_str);
	new_node->len = str_length;
	new_node->next = NULL;

	if (*list_head == NULL)
	{
		*list_head = new_node;
		return (new_node);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new_node;

	return (new_node);
}

