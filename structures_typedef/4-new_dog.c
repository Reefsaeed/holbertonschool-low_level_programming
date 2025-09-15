#include <stdio.h>
#include <stdlib.h>
#include "dog.h"
/* Helper function to calculate string length manually */
int str_len(char *s)
{
int len = 0;
while (s && s[len])
len++;
return len;
}
/* Helper function to copy string manually */
void str_copy(char *dest, char *src)
{
int i = 0;
while (src && src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';
}
/**
* new_dog - creates a new dog
* @name: name of the dog
* @age: age of the dog
* @owner: owner of the dog
*
* Return: pointer to the new dog, or NULL on failure
*/
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *d;
if (!name || !owner)
return (NULL);
d = malloc(sizeof(dog_t));
if (!d)
return (NULL);
d->name = malloc(str_len(name) + 1);
if (!d->name)
{
free(d);
return (NULL);
}
str_copy(d->name, name);
d->owner = malloc(str_len(owner) + 1);
if (!d->owner)
{
free(d->name);
free(d);
return (NULL);
}
str_copy(d->owner, owner);
d->age = age;
return (d);
}
