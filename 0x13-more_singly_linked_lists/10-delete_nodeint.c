#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node in a linked list at a certain index
 * @head: double pointer to the first element in the list
 * @index: index of the node to delete
 *
 * Return: 1 if successful, or -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *prev_node;
	unsigned int i;

	/* Handle empty list */
	if (*head == NULL)
		return (-1);

	/* Handle deleting the head node */
	if (index == 0)
	{
		temp = *head;
		*head = temp->next;
		free(temp);
		return (1);
	}

	/* Find the node before the one to delete */
	prev_node = *head;
	for (i = 0; i < index - 1; i++)
	{
		if (prev_node->next == NULL)
			return (-1); /* Index out of range */
		prev_node = prev_node->next;
	}

	/* Delete the node */
	temp = prev_node->next;
	if (temp == NULL)
		return (-1); /* Index out of range */
	prev_node->next = temp->next;
	free(temp);

	return (1);
}
