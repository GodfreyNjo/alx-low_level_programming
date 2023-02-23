#include <stdio.h>
#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0.
 */
void times_table(void)
{
	int i, result;

		for (i = 0; i <= 10; i++)
			{
			result = i * 9;
			printf("%d x 9 = %d\n", i, result);
			}
}
