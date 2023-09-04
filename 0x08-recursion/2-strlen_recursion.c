#include "main.h"

/**
 * @s: The string to be measured
 * _strlen_recursion - Returns the length of a string
 * Return: Length of the string
 */

int _strlen_recursion(char *s)
{
	int len = 0;

	if (*s)
	{
		len++;
		len += _strlen_recursion(s + 1);
	}

	return (len);
}
