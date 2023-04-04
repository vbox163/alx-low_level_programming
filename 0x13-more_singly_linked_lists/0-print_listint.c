#include "lists.h"

/**
 * print_listint - prints all the elements of a linked list
 * @h: linked list of type listint_t to print
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	/* Initialize a counter */
	size_t num = 0;

	/* Loop through the list and print the value of each node */
	while (h)
	{
		printf("%d\n", h->n);
		num++;
		h = h->next;
	}

	/* Return the number of nodes in the list */
	return (num);
}
