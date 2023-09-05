#include "main.h"
#include <stdlib.h>

/**
 * free_grid - Frees a 2D grid previously created by alloc_grid
 * @grid: The 2D grid to be freed
 * @height: The height dimension of the grid
 *
 * Description: Frees the memory of a 2D grid created by alloc_grid.
 * Return: None
 */
void free_grid(int **grid, int height)
{
	if (grid == NULL || height <= 0)
		return;

	for (int i = 0; i < height; i++)
	{
		free(grid[i]);
	}

	free(grid);
}

