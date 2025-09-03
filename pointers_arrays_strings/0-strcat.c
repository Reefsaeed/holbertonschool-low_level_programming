#include "main.h"
/**
* _strcat - Concatenates two strings
* @dest: Pointer to the destination string
* @src: Pointer to the source string
*
* Return: Pointer to the resulting string dest
*/
char *_strcat(char *dest, char *src)
{
char *start = dest;
/* Find the end of dest string */
while (*dest != '\0')
{
dest++;
}
/* Append src to dest */
while (*src != '\0')
{
*dest = *src;
dest++;
src++;
}
/* Add terminating null byte */
*dest = '\0';
return (start);
}
