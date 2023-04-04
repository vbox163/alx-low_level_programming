#include "lists.h"

/**
 * get_nodeint_at_index - returns the node at a certain index in a linked list
 * @head: pointer to the first node in the linked list
 * @index: index of the node to return
 *
 * Return: pointer to the node at the given index, or NULL if it doesn't exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;
	listint_t *current_node;

	/* Traverse the linked list until the desired index is reached */
	for (i = 0, current_node = head; current_node && i < index; i++)
		current_node = current_node->next;

	/* If the index is valid, return the corresponding node */
	if (current_node != NULL)
		return (current_node);

	/* Otherwise, return NULL */
	return (NULL);
}
