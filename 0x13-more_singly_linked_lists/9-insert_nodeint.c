#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node with given value at a given index
 *
 * @head: pointer to a pointer to the head of the list
 * @idx: index at which to insert the new node
 * @n: value of the new node
 *
 * Return: pointer to the new node, or NULL if failed to allocate memory or idx
 * is out of range
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new_node;
	listint_t *temp = *head;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	/* Initialize the new node */
	new_node->n = n;
	new_node->next = NULL;

	/* Handle the case when the new node is to be inserted at the head of the list */
	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	/* Traverse the list until the desired index is reached */
	for (i = 0; temp && i < idx - 1; i++)
	{
		temp = temp->next;
	}

	/* If the index is out of range, return NULL */
	if (temp == NULL)
	{
		free(new_node);
		return (NULL);
	}

	/* Insert the new node at the desired index */
	new_node->next = temp->next;
	temp->next = new_node;

	return (new_node);
}
