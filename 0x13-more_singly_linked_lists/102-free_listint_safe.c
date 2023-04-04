#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @h: pointer to the pointer of the first node in the linked list
 *
 * Return: number of elements in the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	int diff;
	listint_t *temp, *current;

	if (!h || !*h)  /* If the list is empty or pointer is NULL, return 0 */
		return (0);

	while (*h)  /* Traverse the list */
	{
		diff = *h - (*h)->next;  /* Calculate the difference between current node and the next node */
		if (diff > 0)  /* If the current node is not pointing to itself */
		{
			temp = (*h)->next;  /* Store the next node in a temporary variable */
			free(*h);  /* Free the current node */
			*h = temp;  /* Update the pointer to the current node */
			len++;  /* Increment the counter */
		}
		else  /* If the current node is pointing to itself, indicating a loop */
		{
			free(*h);  /* Free the current node */
			*h = NULL;  /* Set the pointer to NULL to break the loop */
			len++;  /* Increment the counter */
			break;  /* Exit the loop */
		}
	}

	return (len);  /* Return the number of freed elements */
}
