#include "main.h"
/**
 * reverse_array - will reverse array of integers
 * @a: as array
 * @n: as number of elements of array
 *
 * Return: as void
 */
void reverse_array(int *a, int n)
{
	int i;
	int t;

	for (i = 0; i < n--; i++)
	{
		t = a[i];
		a[i] = a[n];
		a[n] = t;
	}
}

