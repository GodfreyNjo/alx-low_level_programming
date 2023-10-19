#include "main.h"

/**
 * power - Calculates the result of raising a base number to an exponent.
 * @x: The base number.
 * @n: The exponent to which the base is raised.
 *
 * This function iteratively multiplies the base by itself, exponent times,
 * to calculate the power. It handles the case of zero exponent correctly by
 * returning 1 in such a case, consistent with mathematical principles.
 *
 * Return: The result of base raised to the exponent (x ^ n).
 */
unsigned long int power(unsigned int x, unsigned int n)
{
	unsigned long int result;
	unsigned int i;

	result = 1;
	for (i = 1; i <= n; i++)
		result *= x;

	return (result);
}

/**
 * print_binary - Prints the binary representation of a number.
 * @num: The unsigned long integer to print in binary.
 *
 * The function calculates the size of an unsigned long int in bits, then
 * iteratively checks each bit of the number to be printed, from the most
 * significant bit to the least significant. It uses bitwise operations to
 * handle the checks and only starts printing once it encounters the first
 * significant bit to avoid leading zeros, except for the
 * representation of zero.
 *
 * Return: Nothing (void).
 */
void print_binary(unsigned long int num)
{
	unsigned long int mask, current_bit;
	char has_started;

	has_started = 0;
	mask = power(2, sizeof(unsigned long int) * 8 - 1);

	while (mask != 0)
	{
		current_bit = num & mask;

		if (current_bit == mask)
		{
			has_started = 1;
			_putchar('1');
		}
		else if (has_started == 1 || mask == 1)
		{
			_putchar('0');
		}

		mask >>= 1;
	}
}

