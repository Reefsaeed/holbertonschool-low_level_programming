#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>
/**
 * sum_them_all - returns the sum of all its parameters
 * @n: number of arguments
 *
 * Return: sum of all arguments, or 0 if n == 0
 */
int sum_them_all(const unsigned int n, ...);

#endif
