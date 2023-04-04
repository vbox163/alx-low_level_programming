/* This file defines a function listint_len that returns the number of nodes in a linked list of type listint_t */

#include "lists.h"

/**

listint_len - returns the number of elements in a linked list

@h: pointer to the head node of the linked list

Return: number of nodes in the linked list
*/
size_t listint_len(const listint_t h)
{
size_t num = 0; / initialize a counter variable */

while (h) /* loop through each node of the linked list /
{
num++; / increment the counter for each node /
h = h->next; / move to the next node */
}

return (num); /* return the final count of nodes */
}





