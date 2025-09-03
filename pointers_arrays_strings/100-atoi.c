#include "main.h"
/**
* _atoi - Converts a string to an integer
* @s: Pointer to the string to convert
*
* Return: The converted integer
*/
int _atoi(char *s)
{
unsigned int result = 0;
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
}
else if (*s >= '0' && *s <= '9')
{
digit_found = 1;
if (result > 214748364 || (result == 214748364 && (*s - '0') > 7))
{
return (sign == 1 ? 2147483647 : -2147483648);
}
result = result * 10 + (*s - '0');
}
else if (digit_found)
{
break;
}
s++;
}
if (sign == -1)
{
if (result == 2147483648U)
return (-2147483648);
else
return (-(int)result);
}
else
{
return ((int)result);
}
}
