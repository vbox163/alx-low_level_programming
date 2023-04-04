/**
 * free_listint2 - frees a linked list
 * @head: pointer to the listint_t list to be freed
 */
void free_listint2(listint_t **head)
{
	/* Declare a temporary node pointer */
	listint_t *temp;

	/* Check if the input pointer is NULL */
	if (head == NULL)
		return;

	/* Loop through the list while there are nodes to be freed */
	while (*head)
	{
		/* Store the next node in the temporary pointer */
		temp = (*head)->next;
		
		/* Free the current node */
		free(*head);
		
		/* Update the input pointer to point to the next node */
		*head = temp;
	}

	/* Set the input pointer to NULL after all nodes are freed */
	*head = NULL;
}
