#include <stdlib.h>
#include "dog.h"
/**
* free_dog - frees memory allocated for a dog
* @d: pointer to the dog to free
*
* Return: void
*/
void free_dog(dog_t *d)
{
if (d)
{
if (d->name)
free(d->name);
if (d->owner)
free(d->owner);
free(d);
}
}
