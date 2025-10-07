#include "lists.h"
#include <stdlib.h>

/**
* add_dnodeint_end - adds a new node at the end of a dlistint_t list
* @head: double pointer to the head of the list
* @n: integer to be added to the new node
*
* Return: address of the new element, or NULL if it failed
*/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
dlistint_t *new_node, *temp;

/* Allocate memory for new node */
new_node = malloc(sizeof(dlistint_t));
if (new_node == NULL)
return (NULL);

/* Initialize new node */
new_node->n = n;
new_node->next = NULL;

/* If list is empty, new node becomes head */
if (*head == NULL)
{
new_node->prev = NULL;
*head = new_node;
return (new_node);
}

/* Traverse to the last node */
temp = *head;
while (temp->next != NULL)
temp = temp->next;

/* Add new node at the end */
temp->next = new_node;
new_node->prev = temp;

return (new_node);
}
