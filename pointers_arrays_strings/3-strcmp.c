#include "main.h"
/**
* _strcmp - Compares two strings
* @s1: Pointer to the first string
* @s2: Pointer to the second string
*
* Return:
* - 0 if strings are equal
* - Negative value if s1 < s2
* - Positive value if s1 > s2
*/
int _strcmp(char *s1, char *s2)
{
while (*s1 != '\0' && *s2 != '\0')
{
if (*s1 != *s2)
{
return (*s1 - *s2);
}
s1++;
s2++;
}
return (*s1 - *s2);
}
