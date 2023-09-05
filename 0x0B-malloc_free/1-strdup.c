#include "main.h"
#include <stdlib.h>

/**
 * _strdup - Duplicates a string.
 * @str: The string to be duplicated.
 *
 * Return: A pointer to the duplicated string, or NULL on failure.
 */
char *_strdup(char *str)
{
	char *duplicate;
	unsigned int length = 0, i;

	if (str == NULL)
		return (NULL);

	/* Calculate the length of the input string */
	while (str[length] != '\0')
		length++;

	/* Allocate memory for the duplicated string */
	duplicate = malloc((length + 1) * sizeof(char));

	if (duplicate == NULL)
		return (NULL);

	/* Copy the characters from the original string to the duplicate */
	for (i = 0; i <= length; i++)
		duplicate[i] = str[i];

	return (duplicate);
}

