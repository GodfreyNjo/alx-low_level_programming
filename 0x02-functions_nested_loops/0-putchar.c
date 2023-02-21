#include "main.h"

/**
 * print_putchar - prints _putchar followed by a newline
 *
 * Return: 0
 */
int print_putchar(void)
{
    char c[] = "_putchar\n";
    int i;

    for (i = 0; i < 9; i++)
        _putchar(c[i]);

    return (0);
}

