#include "main.h"
/**
 * print_triangle - Prints a triangle of a given size
 * @size: The size of the triangle
 */
void print_triangle(int size)
{
int i, j, k;
if (size <= 0)
{
_putchar('\n');
return;
}
for (i = 1; i <= size; i++)
{
/* Print spaces */
for (j = i; j < size; j++)
{
_putchar(' ');
}
/* Print hashes */
for (k = 1; k <= i; k++)
{
_putchar('#');
}
_putchar('\n');
}
}
