#include "main.h"
/**
* cap_string - Capitalizes all words of a string
* @str: Pointer to the string
*
* Return: Pointer to the modified string
*/
char *cap_string(char *str)
{
int i = 0;
int new_word = 1; /* Flag to indicate start of new word */
while (str[i] != '\0')
{
if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
str[i] == ',' || str[i] == ';' || str[i] == '.' ||
str[i] == '!' || str[i] == '?' || str[i] == '"' ||
str[i] == '(' || str[i] == ')' || str[i] == '{' || str[i] == '}')
{
new_word = 1;
}
else if (new_word && str[i] >= 'a' && str[i] <= 'z')
{
str[i] = str[i] - 32;
new_word = 0;
}
else
{
new_word = 0;
}
i++;
}
return (str);
}
