#include "main.h"

/**
 * binary_to_uint - Converts a binary number in a string to an unsigned int.
 * @binary_string: Pointer to a null-terminated string containing
 * a binary number.
 * The function ensures the string consists solely of
 * '0' or '1' characters, then
 * calculates the decimal value of the binary number.
 * If an invalid character is encountered,
 * or if 'binary_string' is NULL, the function returns 0.
 *
 * Return: The unsigned int representation of the binary number,
 * or 0 if an error occurs.
 */
unsigned int binary_to_uint(const char *binary_string)
{
	int idx;
	unsigned int num = 0;

	if (!binary_string)
		return (0);

	for (idx = 0; binary_string[idx] != '\0'; idx++)
	{
		if (binary_string[idx] != '0' && binary_string[idx] != '1')
			return (0);
	}

	for (idx = 0; binary_string[idx] != '\0'; idx++)
	{
		num <<= 1;
		if (binary_string[idx] == '1')
			num += 1;
	}

	return (num);
}

