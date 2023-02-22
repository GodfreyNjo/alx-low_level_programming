#include "main.h"
#include <unistd>

/**
 * _putchar.c - writes the character c to stdout
 * @c. the character to print
 *
 * Return: On success 1
 * On error: -1 is returned and errono is set apprptly
 */
int _putchar(char)
{
	return (write(1, &c, 1));
}
