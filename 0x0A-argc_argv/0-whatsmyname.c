#include <stdio.h>
#include "main.h"

/**
 * main - this will print the program name.
 * @argc: this is  the number of arguments
 * @argv: the array of arguments
 *
 * Return: always 0 (success)
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);
	return (0);
}

