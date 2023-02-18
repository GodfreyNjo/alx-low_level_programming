#include <stdio.h>
/**
 * main - Prints the alphabet in lowercase using only putchar
 *
 * Return: 0 upon successful completion
 */
int main(void)
{
char letter = 'a';

while (letter <= 'z')
{
putchar(letter);
letter++;
}

putchar('\n');

return (0);
}
