#include "main.h"
#include <stdlib.h>

/**
 * clear_bit - Sets the value of a bit to 0 at a specified index.
 * @n: The number to modify.
 * @index: The index at which to clear the bit.
 *
 * This function sets the value of the bit at the given index to 0 by
 * performing a bitwise operation. If the index is out of range,
 * it returns -1.
 *
 * Return: 1 if the operation was successful, or -1 for an error.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > sizeof(n) * 8)
		return (-1);

	*n &= ~(1 << index);

	return (1);
}

