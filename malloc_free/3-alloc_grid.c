#include <stdlib.h>
#include "main.h"
/**
* alloc_grid - returns a pointer to a 2D array of integers
* @width: number of columns
* @height: number of rows
*
* Return: pointer to the 2D array, or NULL on failure
*/
int **alloc_grid(int width, int height)
{
int **grid;
int i, j;
if (width <= 0 || height <= 0)
return (NULL);
grid = malloc(height * sizeof(int *));
if (grid == NULL)
return (NULL);
for (i = 0; i < height; i++)
{
grid[i] = malloc(width * sizeof(int));
if (grid[i] == NULL)
{
/* Free already allocated rows before failure */
while (i > 0)
{
i--;
free(grid[i]);
}
free(grid);
return (NULL);
}
/* Initialize row with zeros */
for (j = 0; j < width; j++)
grid[i][j] = 0;
}
return (grid);
}
