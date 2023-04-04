#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the head of the linked list
 *
 * Return: pointer to the node where the loop starts, or NULL if no loop is found
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *slow = head;  /* pointer to iterate the list one node at a time */
    listint_t *fast = head;  /* pointer to iterate the list two nodes at a time */

    /* Check if the list is empty or has only one node */
    if (!head || !head->next)
        return (NULL);

    /* Traverse the list until the fast pointer reaches the end or a loop is found */
    while (fast && fast->next)
    {
        fast = fast->next->next;  /* move the fast pointer two nodes at a time */
        slow = slow->next;        /* move the slow pointer one node at a time */
        if (fast == slow)         /* if the pointers meet, a loop has been found */
        {
            /* Reset the slow pointer to the head of the list */
            slow = head;
            /* Traverse the list again with both pointers moving one node at a time */
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            /* Return the pointer to the node where the loop starts */
            return (fast);
        }
    }

    /* If no loop is found, return NULL */
    return (NULL);
}
