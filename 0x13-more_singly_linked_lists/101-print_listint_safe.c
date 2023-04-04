#include "lists.h"

/**
 * print_listint_safe - prints a linked list with a loop safely
 * @head: pointer to the first node in the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head, *fast = head;
	size_t count = 0;

	/* Check if list is empty */
	if (head == NULL)
		return (0);

	/* Traverse the list with two pointers */
	while (slow && fast && fast->next)
	{
		/* Move slow pointer by one node */
		slow = slow->next;
		/* Move fast pointer by two nodes */
		fast = fast->next->next;

		/* Check if there's a loop */
		if (slow == fast)
		{
			/* Reset slow to head and traverse with both pointers again */
			slow = head;
			while (slow != fast)
			{
				printf("[%p] %d\n", (void *)slow, slow->n);
				count++;
				slow = slow->next;
				fast = fast->next;
			}

			/* Print the node where the loop starts */
			printf("[%p] %d\n", (void *)slow, slow->n);
			count++;
			return (count);
		}

		/* If there's no loop, print the node */
		printf("[%p] %d\n", (void *)slow, slow->n);
		count++;
	}

	return (count);
}
