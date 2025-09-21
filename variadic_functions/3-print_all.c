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
/* First if: handle separator */
if (printed && (current_char == 'c' || current_char == 'i' || 
current_char == 'f' || current_char == 's'))
printf(", ");
/* Second if: handle all valid format specifiers */
if (current_char == 'c' || current_char == 'i' || 
current_char == 'f' || current_char == 's')
{
printed = 1;
/* Handle each format specifier without additional if statements */
switch (current_char)
{
case 'c':
printf("%c", va_arg(args, int));
break;
case 'i':
printf("%d", va_arg(args, int));
break;
case 'f':
printf("%f", va_arg(args, double));
break;
case 's':
str = va_arg(args, char *);
printf("%s", str ? str : "(nil)");
break;
}
}
i++;
}
va_end(args);
printf("\n");
}
