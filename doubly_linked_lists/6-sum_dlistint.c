#include "lists.h"

/**
* sum_dlistint - returns the sum of all the data (n) of a dlistint_t linked list
* @head: pointer to the head of the list
*
* Return: sum of all data, or 0 if list is empty
*/
int sum_dlistint(dlistint_t *head)
{
int sum = 0;
dlistint_t *current = head;

/* Traverse the list and accumulate the sum */
while (current != NULL)
{
sum += current->n;
current = current->next;
}

return (sum);
}
