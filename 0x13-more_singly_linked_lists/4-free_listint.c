#include "lists.h"

/**
 * free_listint - frees a linked list
 * @head: pointer to the first node in the linked list
 */
void free_listint(listint_t *head)
{
    listint_t *temp;  // Temporary node to hold the next node to free

    // Traverse the list, freeing each node one by one
    while (head)
    {
        temp = head->next; // Store the next node to free
        free(head);        // Free the current node
        head = temp;       // Move to the next node
    }
}
