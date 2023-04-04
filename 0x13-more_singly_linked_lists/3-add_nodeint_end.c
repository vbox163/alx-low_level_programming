/**
 * add_nodeint_end - adds a node at the end of a linked list
 * @head: pointer to the first element in the list
 * @n: data to insert in the new element
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node;
	listint_t *last_node = *head;

	/* allocate memory for the new node */
	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	/* populate the new node */
	new_node->n = n;
	new_node->next = NULL;

	/* if the list is empty, make the new node the first node */
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	/* traverse the list until the last node is reached */
	while (last_node->next)
		last_node = last_node->next;

	/* add the new node to the end of the list */
	last_node->next = new_node;

	return (new_node);
}
