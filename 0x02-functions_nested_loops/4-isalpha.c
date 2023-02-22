#include "main.h"

/**
 * _isalpha - checks if a charscter is an alphabet
 * @C: The character to check
 *
 * Return: 1 if c is a leter, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
