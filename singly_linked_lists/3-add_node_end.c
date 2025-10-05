#include "lists.h"
#include <string.h>
#include <stdlib.h>
/**
* add_node_end - adds a new node at the end of a list_t list
* @head: double pointer to the head of the list
* @str: string to be duplicated and added to the new node
*
* Return: address of the new element, or NULL if it failed
*/
list_t *add_node_end(list_t **head, const char *str)
{
list_t *new_node, *temp;
char *str_dup;
unsigned int len = 0;
new_node = malloc(sizeof(list_t));
if (new_node == NULL)
return (NULL);
if (str == NULL)
{
str_dup = NULL;
len = 0;
}
else
{
str_dup = strdup(str);
if (str_dup == NULL)
{
free(new_node);
return (NULL);
}
while (str[len])
len++;
}
new_node->str = str_dup;
new_node->len = len;
new_node->next = NULL;
if (*head == NULL)
{
*head = new_node;
return (new_node);
}
temp = *head;
while (temp->next != NULL)
temp = temp->next;
temp->next = new_node;
return (new_node);
}
