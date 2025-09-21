#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
/**
* print_all - Prints anything based on the format string
* @format: List of types of arguments (c: char, i: int, f: float, s: char*)
* @...: Variable arguments to print
*/
void print_all(const char * const format, ...)
{
va_list args;
int i = 0;
char *str;
char current_char;
int printed = 0;
va_start(args, format);
while (format && format[i])
{
current_char = format[i];
if (printed && (current_char == 'c' || current_char == 'i' || 
current_char == 'f' || current_char == 's'))
{
printf(", ");
}
if (current_char == 'c')
{
printf("%c", va_arg(args, int));
printed = 1;
}
else if (current_char == 'i')
{
printf("%d", va_arg(args, int));
printed = 1;
}
else if (current_char == 'f')
{
printf("%f", va_arg(args, double));
printed = 1;
}
else if (current_char == 's')
{
str = va_arg(args, char *);
if (str == NULL)
printf("(nil)");
else
printf("%s", str);
printed = 1;
}
i++;
}
va_end(args);
printf("\n");
}
