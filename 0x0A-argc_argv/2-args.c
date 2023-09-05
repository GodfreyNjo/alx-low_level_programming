#include <stdio.h>
#include "main.h"

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
int i;

for (i = 0; i < argc; i++)
{
int j = 0;

while (argv[i][j] != '\0')
{
_putchar(argv[i][j]);
j++;
}
_putchar('\n');
}

return (0);
}

