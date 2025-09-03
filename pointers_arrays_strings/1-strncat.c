#include "main.h"
/**
* _strncat - Concatenates two strings with byte limit
* @dest: Pointer to the destination string
* @src: Pointer to the source string
* @n: Maximum number of bytes to use from src
*
* Return: Pointer to the resulting string dest
*/
char *_strncat(char *dest, char *src, int n)
{
char *start = dest;
while (*dest != '\0')
{
dest++;
}
while (n > 0 && *src != '\0')
{
*dest = *src;
dest++;
src++;
n--;
}
*dest = '\0';
return (start);
}
