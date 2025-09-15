#include <stdlib.h>
#include "main.h"
/**
* _calloc - allocates memory for an array of nmemb elements of size bytes
* @nmemb: number of elements
* @size: size of each element
*
* Return: pointer to allocated memory (zero-initialized), or NULL on failure
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
void *ptr;
unsigned int total_size;
unsigned char *p;
unsigned int i;
if (nmemb == 0 || size == 0)
return (NULL);
total_size = nmemb * size;
/* Prevent integer overflow */
if (size != 0 && total_size / size != nmemb)
return (NULL);
ptr = malloc(total_size);
if (ptr == NULL)
return (NULL);
p = (unsigned char *)ptr;
for (i = 0; i < total_size; i++)
p[i] = 0;
return (ptr);
}
