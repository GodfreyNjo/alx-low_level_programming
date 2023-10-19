#include "main.h"

/**
 * get_bit - Check and return the value of a bit at a specified index.
 * @n: The number to inspect.
 * @index: The index at which to examine the bit.
 *
 * This function calculates the value of the bit at the given index by
 * performing a bitwise check. If the index is out of range, it returns -1.
 *
 * Return: The value of the bit (0 or 1) or -1 for an out-of-range index.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int divisor, check;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	divisor = 1 << index;
	check = n & divisor;
	if (check == divisor)
		return (1);
	return (0);
}

