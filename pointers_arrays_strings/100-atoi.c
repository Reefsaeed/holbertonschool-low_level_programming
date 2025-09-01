#include "main.h"
/**
 * _atoi - Converts a string to an integer
 * @s: Pointer to the string to convert
 *
 * Return: The converted integer
 */
int _atoi(char *s)
{
int result = 0;
int sign = 1;
int started = 0;
while (*s != '\0')
{
if (*s == '-')
{
sign *= -1;
}
else if (*s == '+')
{
/* Do nothing, sign remains the same */
}
else if (*s >= '0' && *s <= '9')
{
started = 1;
result = result * 10 + (*s - '0');
}
else if (started)
{
/* If we already started reading digits and encounter non-digit, stop */
break;
}
s++;
}
return (result *sign);
}
