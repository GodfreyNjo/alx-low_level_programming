#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * free_grid_2d_array - Frees a 2D array
 * @grid: The 2D array to be freed
 * @height: The height dimension of the grid
 *
 * Description: Frees the memory of a 2D array.
 * Return: None
 */
void free_grid_2d_array(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}

