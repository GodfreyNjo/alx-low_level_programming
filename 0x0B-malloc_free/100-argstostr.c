#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Convert command line arguments to a single string
 * @ac: Number of arguments
 * @av: Array of argument strings
 *
 * Return: A pointer to a new string containing the arguments (Success),
 * or NULL (Error)
 */
char *argstostr(int ac, char **av)
{
	int i, j, r = 0, l = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			l++;
	}
	l += ac;

	str = malloc(sizeof(char) * l + 1);
	if (str == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			str[r] = av[i][j];
			r++;
		}
		if (str[r] == '\0')
		{
			str[r++] = '\n';
		}
	}
	return (str);
}

