#include <stddef.h>

/**
 * array_iterator - Executes a function on each element of an array.
 * @array: The array to iterate over.
 * @size: The size of the array.
 * @action: A pointer to the function to execute on each element.
 *
 * Description: This function takes an array, its size, and a function pointer
 * 'action'. It applies 'action' to each element of the array.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	if (array != NULL && action != NULL)
	{
		size_t i;

		for (i = 0; i < size; i++)
		{
			action(array[i]);
		}
	}
}

