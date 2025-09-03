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
int digit_found = 0;
while (*s != '\0')
{
if (*s == '-')
{
sign *= -1;
}
else if (*s == '+')
{
/* Sign remains positive */
}
else if (*s >= '0' && *s <= '9')
{
digit_found = 1;
/* Check for overflow before updating result */
if (sign == 1)
{
if (result > 214748364 || (result == 214748364 && (*s - '0') > 7))
return (2147483647);
}
else
{
if (result > 214748364 || (result == 214748364 && (*s - '0') > 8))
return (-2147483648);
}
result = result * 10 + (*s - '0');
}
else if (digit_found)
{
/* Stop if we found digits and then encounter non-digit */
break;
}
s++;
}
return (result *sign);
}
