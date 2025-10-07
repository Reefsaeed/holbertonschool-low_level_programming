#include "lists.h"
#include <stdlib.h>

/**
* insert_dnodeint_at_index - inserts a new node at a given position
* @h: double pointer to the head of the list
* @idx: index where the new node should be added
* @n: data for the new node
*
* Return: address of the new node, or NULL if it failed
*/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *new_node, *current;
unsigned int i;

if (h == NULL)
return (NULL);

/* If inserting at index 0, use add_dnodeint */
if (idx == 0)
return (add_dnodeint(h, n));

/* Traverse to the node before the desired index */
current = *h;
for (i = 0; current != NULL && i < idx - 1; i++)
current = current->next;

/* If we reached end before desired index, return NULL */
if (current == NULL)
return (NULL);

/* If inserting at the end, use add_dnodeint_end */
if (current->next == NULL)
return (add_dnodeint_end(h, n));

/* Create new node */
new_node = malloc(sizeof(dlistint_t));
if (new_node == NULL)
return (NULL);

/* Initialize new node */
new_node->n = n;
new_node->prev = current;
new_node->next = current->next;

/* Update surrounding nodes */
current->next->prev = new_node;
current->next = new_node;

return (new_node);
}
