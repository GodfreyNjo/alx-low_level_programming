#include "main.h"
#include <stdlib.h>
#include <stdio.h>

#define ERROR_MSG "Error"

/**
 * is_valid_digit - Checks if a string contains only digits.
 * @str: The string to be evaluated.
 *
 * Return: 1 if all characters are digits, 0 otherwise.
 */
int is_valid_digit(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - Returns the length of a string.
 * @str: The string to evaluate.
 *
 * Return: The length of the string.
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}

/**
 * handle_errors - Handles errors for the main function.
 */
void handle_errors(void)
{
	printf("%s\n", ERROR_MSG);
	exit(98);
}

/**
 * multiply_numbers - Multiplies two numbers represented as strings.
 * @num1: The first number as a string.
 * @num2: The second number as a string.
 * @result: The array to store the result.
 */
void multiply_numbers(char *num1, char *num2, int *result)
{
	int len1 = _strlen(num1);
	int len2 = _strlen(num2);

	for (int i = 0; i <= len1 + len2; i++)
		result[i] = 0;

	for (int i = len1 - 1; i >= 0; i--)
	{
		int digit1 = num1[i] - '0';
		int carry = 0;
		for (int j = len2 - 1; j >= 0; j--)

		{

			int digit2 = num2[j] - '0';
			carry += result[i + j + 1] + (digit1 * digit2);
			result[i + j + 1] = carry % 10;
			carry /= 10;

		}
		
		if (carry > 0)
			result[i + len2 + 1] += carry;
	}

}

/**
 * print_result - Prints the result stored in the array.
 * @result: The array containing the result.
 */
void print_result(int *result)
{
	int started = 0;
	for (int i = 0; result[i] != '\0'; i++)
	{
		if (result[i])
			started = 1;
		if (started)
			putchar(result[i] + '0');
	}
	if (!started)
		putchar('0');
	putchar('\n');
}

/**
 * main - Multiplies two positive numbers.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 *
 * Return: Always 0 (Success).
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int *result;

	num1 = argv[1];
	num2 = argv[2];
	if (argc != 3 || !is_valid_digit(num1) || !is_valid_digit(num2))
		handle_errors();

	int total_len = _strlen(num1) + _strlen(num2) + 1;
	result = malloc(sizeof(int) * total_len);
	if (!result)
		return (1);

	multiply_numbers(num1, num2, result);
	print_result(result);

	free(result);
	return (0);
}

