#include <stdio.h>
/**
* main - prints the name of the program
* @argc: number of arguments
* @argv: array of arguments
*
* Return: Always 0
*/
int main(int argc, char *argv[])
{
(void)argc; /* we don't need argc, so silence unused var warning */
printf("%s\n", argv[0]);
return (0);
}
