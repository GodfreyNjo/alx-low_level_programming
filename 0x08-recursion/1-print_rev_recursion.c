#include "main.h"
/**
 * _print_rev_recursion - will print a string in reverse.
 * @s: is the  string to be printed.
 */
void _print_rev_recursion(char *s)
{
	if (*s)
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
}

