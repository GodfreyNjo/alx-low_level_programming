#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a specified index.
 * @n: The number to modify.
 * @index: The index at which to set the bit.
 *
 * This function sets the value of the bit at the given index to 1 by
 * performing a bitwise operation. If the index is out of range,
 * it returns -1.
 *
 * Return: 1 if the operation was successful, or -1 for an error.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);

	mask = 1 << index;
	*n = *n | mask;

	return (1);
}

