#include <stdlib.h>
#include "main.h"

/**
 * array_range - Creates an array of integers within a given range
 * @min_value: The minimum value of the range
 * @max_value: The maximum value of the range (inclusive)
 *
 * Return: A pointer to the newly created integer array
 */
int *array_range(int min_value, int max_value)
{
	int *result_array;
	int current_value, array_size, i;

	if (min_value > max_value)
		return (NULL);

	array_size = max_value - min_value + 1;

	result_array = malloc(sizeof(int) * array_size);

	if (result_array == NULL)
		return (NULL);

	current_value = min_value;

	for (i = 0; i < array_size; i++)
	{
		result_array[i] = current_value;
		current_value++;
	}

	return (result_array);
}

