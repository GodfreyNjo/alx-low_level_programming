#include <stdio.h>
#includ "main.h"

/**
 * add - adds two integers
 *
 * @a: first integer to be added
 * @b: second integer to be added
 *
 * Return: the result of the addition
 */
int add(int a, int b)
{
	int x = 5;
	int y = 10;
	int z = add(x + y);

	printf("%d + %d + %d\n", x, y, z);

	return (0);
}
