#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a linked list
 * @head: pointer to the first node in the list
 * @n: data to insert in that new node
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;  /* Declare a pointer to a new node */

	/* Allocate memory for the new node */
	new = malloc(sizeof(listint_t));
	if (!new)  /* If memory allocation failed, return NULL */
		return (NULL);

	new->n = n;  /* Set the data of the new node to the input data */
	new->next = *head;  /* Set the next pointer of the new node to the head */
	*head = new;  /* Update the head to point to the new node */

	return (new);  /* Return a pointer to the new node */
}
