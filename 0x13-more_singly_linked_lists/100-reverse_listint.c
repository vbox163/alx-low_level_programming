#include "lists.h"

/**
 * reverse_listint - Reverses a linked list of type listint_t.
 * @head: Pointer to a pointer to the head node of the list.
 *
 * Return: Pointer to the first node in the new list.
 */
listint_t *reverse_listint(listint_t **head)
{
    listint_t *prev = NULL;  /* pointer to the previous node */
    listint_t *next = NULL;  /* pointer to the next node */

    /* loop through the list while the current node is not NULL */
    while (*head != NULL)
    {
        next = (*head)->next;    /* store the pointer to the next node */
        (*head)->next = prev;    /* change the current node's pointer to the previous node */
        prev = *head;            /* update the pointer to the previous node */
        *head = next;            /* move to the next node in the list */
    }

    *head = prev;   /* update the head pointer to point to the last node (new first node) */

    return (*head);
}
