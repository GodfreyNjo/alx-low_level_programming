#include <stdlib.h>
#include "main.h"

/**
 * array_range - Creates an array of integers
 * from min to max (inclusive)
 * @min: The minimum value
 * @max: The maximum value
 *
 * Return: Pointer to the newly created array,
 * NULL on failure or invalid input
 */
int *array_range(int min, int max)
{
	if (min > max)
		return (NULL);

	int *array = malloc(sizeof(int) * (max - min + 1));

	if (array == NULL)
		return (NULL);

	for (int i = 0; min <= max; i++)
	{
		array[i] = min;
		min++;
	}

	return (array);
}

