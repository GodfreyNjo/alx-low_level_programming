#include "main.h"

/**
* a function that will print string
* @s: The string to be printed.
**/

void _puts_recursion(char *s);
{
	if (*s == '\0')//Base case

	{putchar('\n');
return;
}
putchar(*s);
_puts_recursion(s + 1);
}


