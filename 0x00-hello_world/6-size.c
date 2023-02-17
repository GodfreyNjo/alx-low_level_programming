#include <stdio.h>
#include <stdint.h>

/**
 * main - Entry point
 *
 * Description: Prints the sizes of various data types in bytes.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
printf("Size of a char: %lu byte(s)\n", sizeof(char));
printf("Size of an int: %lu byte(s)\n", sizeof(int));
printf("Size of a int32_t: %lu byte(s)\n", sizeof(int32_t));
printf("Size of a int64_t: %lu byte(s)\n", sizeof(int64_t));
printf("Size of a float: %lu byte(s)\n", sizeof(float));
printf("Size of a double: %lu byte(s)\n", sizeof(double));
printf("Size of a long double: %lu byte(s)\n", sizeof(long double));

return (0);
}
