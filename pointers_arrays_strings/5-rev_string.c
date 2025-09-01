#include "main.h"
/**
 * rev_string - Reverses a string in place
 * @s: Pointer to the string to be reversed
 *
 * Return: void
 */
void rev_string(char *s)
{
int length = 0;
int start = 0;
int end;
char temp;
/* Calculate the length of the string */
while (s[length] != '\0')
{
length++;
}
end = length - 1;
/* Swap characters from start and end moving towards the center */
while (start < end)
{
temp = s[start];
s[start] = s[end];
s[end] = temp;
start++;
end--;
}
}
