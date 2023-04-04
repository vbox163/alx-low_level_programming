#include "lists.h"
/**
 * pop_listint - deletes the head node of a linked list
 * @head: pointer to the first element in the linked list
 *
 * Return: the data inside the element that was deleted,
 *         or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
  listint_t *temp;  /* a temporary pointer to the next node in the list */
  int num;          /* the value stored in the head node */

  /* Check if the list is empty or the head pointer is NULL */
	if (!head || !*head)
		return (0);

	/* Store the value in the head node */
	num = (*head)->n;

	/* Move the head pointer to the next node in the list */
	temp = (*head)->next;
	free(*head);    /* free the memory used by the head node*/
	*head = temp;   /* update the head pointer to point to the new head node*/

	return (num);   /* return the value stored in the head node*/
}
