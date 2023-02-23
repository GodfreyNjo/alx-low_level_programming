#include "main.h"
#include <stdlib.h>

/**
 * print_last_digit - Prints the lastdigit of a anumber
 * @n: is the number to check
 *
 * Return: the value of the last digit of n
 */
int  print_last_digit(int n)
{
	int  last_digit = abs(n) % 10;

	_putchar('0' + last_digit);

	return (last_digit);
}

