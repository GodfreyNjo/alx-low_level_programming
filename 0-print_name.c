#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name - Prints a name using a callback function.
 * @name: The name to be printed.
 * @f: A function pointer to the callback function.
 *
 * Description: This function takes a name as input and a callback function
 * pointer 'f' that is responsible for printing the name. The callback function
 * should have the prototype 'void function_name(char *)'.
 */

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}

