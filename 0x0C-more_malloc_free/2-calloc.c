#include <stdlib.h>
#include "main.h"

/**
 * custom_memset - Fills memory with a constant byte
 * @s: Memory area to be filled
 * @b: Char to copy
 * @n: Number of times to copy b
 *
 * Return: Pointer to the memory area s
 */
char *custom_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}

/**
 * custom_calloc - Allocates memory for an array
 * @nmemb: Number of elements in the array
 * @size: Size of each element
 *
 * Return: Pointer to allocated memory
 */
void *custom_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(size * nmemb);

	if (ptr == NULL)
		return (NULL);

	custom_memset(ptr, 0, nmemb * size);

	return (ptr);
}

