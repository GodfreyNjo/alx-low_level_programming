#include "main.h"
#include <stdio.h>

/**
 * get_endianness - Checks the endianness of the system.
 *
 * Return: 0 if the system is big endian, 1 if it's little endian.
 */
int get_endianness(void)
{
	unsigned int test = 1;
	char *byte = (char *)&test;

	return ((byte[0] == 1) ? 1 : 0);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int endianness = get_endianness();

	if (endianness == 0)
		printf("This system is big endian.\n");
	else
		printf("This system is little endian.\n");

	return (0);
}

