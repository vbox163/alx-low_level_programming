#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
    int n;                      /* integer value stored in the node */
    struct listint_s *next;     /* pointer to the next node in the list */
} listint_t;

/* Function declarations */

/* Print all elements of a linked list and return the number of nodes */
size_t print_listint(const listint_t *h);

/* Count the number of nodes in a linked list */
size_t listint_len(const listint_t *h);

/* Add a new node at the beginning of a linked list */
listint_t *add_nodeint(listint_t **head, const int n);

/* Add a new node at the end of a linked list */
listint_t *add_nodeint_end(listint_t **head, const int n);

/* Free a linked list */
void free_listint(listint_t *head);

/* Free a linked list and set the head to NULL */
void free_listint2(listint_t **head);

/* Remove the first node of a linked list and return its value */
int pop_listint(listint_t **head);

/* Return a pointer to the node at a given index in a linked list */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index);

/* Return the sum of all elements in a linked list */
int sum_listint(listint_t *head);

/* Insert a new node at a given index in a linked list */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n);

/* Delete a node at a given index in a linked list */
int delete_nodeint_at_index(listint_t **head, unsigned int index);

/* Reverse a linked list */
listint_t *reverse_listint(listint_t **head);

/* Print all elements of a linked list safely (without infinite loops) */
size_t print_listint_safe(const listint_t *head);

/* Free a linked list safely (without infinite loops) */
size_t free_listint_safe(listint_t **h);

/* Find the node where a linked list loops (if it exists) */
listint_t *find_listint_loop(listint_t *head);

#endif
