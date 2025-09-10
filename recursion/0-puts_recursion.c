#include "main.h"
/**
* _puts_recursion - prints a string followed by a new line
* @s: string to print
*/
void _puts_recursion(char *s)
{
if (*s == '\0')  /* base case: end of string */
{
_putchar('\n');
return;
}
_putchar(*s);        /* print current character */
_puts_recursion(s + 1); /* recurse with the rest of the string */
}
