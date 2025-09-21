#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
/**
* print_numbers - Prints numbers, followed by a new line
* @separator: The string to be printed between numbers
* @n: The number of integers passed to the function
* @...: The variable number of integers to print
*
* Description: If separator is NULL, it doesn't print it.
*              Prints a new line at the end.
*/
void print_numbers(const char *separator, const unsigned int n, ...)
{
va_list args;
unsigned int i;
/* Initialize the argument list */
va_start(args, n);
/* Iterate through all the arguments */
for (i = 0; i < n; i++)
{
/* Print the current number */
printf("%d", va_arg(args, int));
/* Print separator if it's not NULL and not the last number */
if (separator != NULL && i < n - 1)
{
printf("%s", separator);
}
}
/* Clean up the argument list */
va_end(args);
/* Print new line at the end */
printf("\n");
}
