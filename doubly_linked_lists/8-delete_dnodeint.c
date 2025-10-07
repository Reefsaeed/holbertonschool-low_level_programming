#include "lists.h"
#include <stdlib.h>

/**
* delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
* @head: double pointer to the head of the list
* @index: index of the node to delete
*
* Return: 1 if succeeded, -1 if failed
*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *current;
unsigned int i;

if (head == NULL || *head == NULL)
return (-1);

current = *head;

/* Delete the first node */
if (index == 0)
{
*head = current->next;
if (*head != NULL)
(*head)->prev = NULL;
free(current);
return (1);
}

/* Traverse to the node at the given index */
for (i = 0; current != NULL && i < index; i++)
current = current->next;

/* If index is out of bounds */
if (current == NULL)
return (-1);

/* Update the previous node's next pointer */
if (current->prev != NULL)
current->prev->next = current->next;

/* Update the next node's previous pointer */
if (current->next != NULL)
current->next->prev = current->prev;

/* Free the node */
free(current);
return (1);
}
