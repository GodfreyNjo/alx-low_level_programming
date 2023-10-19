#include "main.h"

/**
 * flip_bits - Counts the number of bits to change between two numbers.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits that need to be flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int bit_index, flip_count = 0;
	unsigned long int diff = n ^ m;

	for (bit_index = 0; bit_index < 64; bit_index++)
	{
		if ((diff >> bit_index) & 1)
			flip_count++;
	}

	return (flip_count);
}

