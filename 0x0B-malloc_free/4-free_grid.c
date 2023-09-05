#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * free_grid - frees 2d array previously created
 * @grid: 2d grid to be created
 * @height: the height dimension of grid
 *
 * Description: frees memory of grid created
 * by allo_grid.
 *
 * Return: none
 *
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}

