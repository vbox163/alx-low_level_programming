#include "lists.h"

/**
 * sum_listint - calculates the sum of all the data in a listint_t list
 * @head: pointer to the first element of the linked list
 *
 * Return: resulting sum of all the elements
 */
int sum_listint(listint_t *head)
{
	/* initialize the sum to zero */
	int sum = 0;
	/* create a temporary pointer to traverse the linked list */
	listint_t *temp = head;

	/* traverse the linked list and add up the values of all nodes */
	while (temp)
	{
		sum += temp->n;
		temp = temp->next;
	}

	/* return the resulting sum */
	return (sum);
}
