#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: Pointer to a string of 0 and 1 characters.
 *
 * This function parses a string containing a binary number and converts
 * it into the corresponding unsigned integer. The parsing process validates
 * the presence of only '0' or '1' characters in the string; otherwise,
 * it returns 0 for any invalid input.
 * It goes through each character only once,
 * avoiding unnecessary iterations and checks, making the loop more efficient.
 *
 * Return: The converted unsigned int value, or 0 if there is an error (e.g.,
 * non-binary characters in the input string, or b is NULL).
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;

	if (!b)
		return (0);

	for (int a = 0; b[a] != '\0'; a++)
	{
		if (b[a] == '1')
		{
			num = (num << 1) + 1;
		}
		else if (b[a] == '0')
		{
			num <<= 1;
		}
		else
		{
			return (0);
		}
	}

	return (num);
}

