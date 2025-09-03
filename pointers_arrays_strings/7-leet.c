#include "main.h"
/**
* leet - Encodes a string into 1337
* @str: Pointer to the string
*
* Return: Pointer to the modified string
*/
char *leet(char *str)
{
char *letters = "aAeEoOtTlL";
char *replace = "4433007711";
int i, j;
for (i = 0; str[i] != '\0'; i++)
{
for (j = 0; letters[j] != '\0'; j++)
{
if (str[i] == letters[j])
{
str[i] = replace[j];
break;
}
}
}
return (str);
}
