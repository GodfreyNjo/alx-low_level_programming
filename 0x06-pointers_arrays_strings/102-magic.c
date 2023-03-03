#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int n;
int a[5];
int *p;

a[2] = 1024;
p = &n;

/* Update the value of the third element of the array to be 98 */
*(a + 2) = 98;

/* Print the value of a[2] */
printf("a[2] = %d\n", a[2]);
return (0);
}

