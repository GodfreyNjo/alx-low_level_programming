#include "main.h"

/**
 * determine_endianness - Check the system's endianness.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int determine_endianness(void)
{
	int test_value;
	char *byte_ptr;

	test_value = 1;
	byte_ptr = (char *)&test_value;

	return (*byte_ptr);
}

