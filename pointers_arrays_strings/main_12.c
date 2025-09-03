#include "main.h"
#include <stdio.h>
/**
 * main - test the _atoi function with edge cases
 *
 * Return: Always 0.
 */
int main(void)
{
int nb;
/* Test case that should return INT_MIN (-2147483648) */
nb = _atoi("-2147483648");
printf("%d\n", nb);
return (0);
}
