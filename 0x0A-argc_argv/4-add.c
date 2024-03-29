#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/**
 * check_num - Check string if there are digit.
 *
 * @str: array str.
 *
 * Return: Always 0 (Success)
 */
int check_num(char *str)
{
	unsigned int count;

	count = 0;
	while (count < strlen(str)) /*count string*/

	{
		if (!isdigit(str[count]))
		{
			return (0);
		}

		count++;
	}
	return (1);
}

/**
 * main - Print the name of the program.
 * @argc: Count arguments.
 * @argv: the arguments
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])

{

	int count;
	int str_to_int;
	int sum = 0;

	count = 1;
	while (count < argc)
	{
		if (check_num(argv[count]))

		{
			str_to_int = atoi(argv[count]); /* atoi fun  convert string to int*/
			sum += str_to_int;
		}

		/*Condition*/
		else
		{
			printf("Error\n");
			return (1);
		}

		count++;
	}

	printf("%d\n", sum); /*prints sum*/

	return (0);
}




