#include "lists.h"

/**
* get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
* @head: pointer to the head of the list
* @index: index of the node, starting from 0
*
* Return: pointer to the nth node, or NULL if it doesn't exist
*/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
unsigned int count = 0;
dlistint_t *current = head;

/* Traverse the list until we reach the desired index or end */
while (current != NULL)
{
if (count == index)
return (current);

count++;
current = current->next;
}

/* If we reach here, the index is out of bounds */
return (NULL);
}
