#include "main.h"

/**
 *@s: The string to be printed.
 *_print_rev_recursion - Prints a string in reverse.
 */

void _print_rev_recursion(char *s)
{
	if (*s)
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
}
