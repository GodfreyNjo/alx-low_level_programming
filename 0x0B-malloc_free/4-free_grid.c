#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * free2DGrid - Frees a 2D grid
 * @grid: The 2D grid to free
 * @height: The height dimension of the grid
 *
 * Description: This function frees the memory allocated for a 2D grid.
 *
 * Return: Nothing
 */
void free2DGrid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}

