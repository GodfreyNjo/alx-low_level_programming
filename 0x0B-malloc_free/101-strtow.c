#include <stdlib.h>
#include "main.h"

/**
 * countWords - Helper function to count the number of words in a string
 * @s: The input string
 *
 * Return: The number of words
 */
int countWords(char *s)
{
	int flag, c, wordCount;

	flag = 0;
	wordCount = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			wordCount++;
		}
	}

	return (wordCount);
}

/**
 * strtow - Splits a string into words
 * @str: The input string to split
 *
 * Return: A pointer to an array of strings (Success), or NULL (Error)
 */
char **strtow(char *str)
{
	char **wordArray, *temp;
	int i, k = 0, len = 0, wordCount, c = 0, start, end;

	while (*(str + len))
		len++;
	wordCount = countWords(str);
	if (wordCount == 0)
		return (NULL);

	wordArray = (char **)malloc(sizeof(char *) * (wordCount + 1));
	if (wordArray == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				end = i;
				temp = (char *)malloc(sizeof(char) * (c + 1));
				if (temp == NULL)
					return (NULL);
				while (start < end)
					*temp++ = str[start++];
				*temp = '\0';
				wordArray[k] = temp - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	wordArray[k] = NULL;

	return (wordArray);
}

