#include "main.h"
#include <stdlib.h>

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: 0 if successful, 1 if there are not enough arguments
 */
int main(int argc, char *argv[])
{
if (argc != 3)
{
/* Print an error message and return 1 if not enough arguments */
_puts("Error");
_putchar('\n');
return (1);
}

/* Convert the input strings to integers */
int num1 = atoi(argv[1]);
int num2 = atoi(argv[2]);

/* Calculate the result of multiplication */
int result = num1 * num2;

/* Print the result followed by a newline character */
_putchar(result / 10 + '0');
_putchar(result % 10 + '0');
_putchar('\n');

return (0);
}

