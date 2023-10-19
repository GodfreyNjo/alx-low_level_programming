#include <unistd.h>

/**
 * _putchar - Outputs a single character to the standard output.
 * @c: The character to be printed.
 *
 * This function writes a single character to the standard output (stdout),
 * using the 'write' system call, which sends one byte of data
 * from the character 'c'
 * to file descriptor 1, which is linked to the console output.
 * This low-level operation
 * might be preferred for its execution speed or to bypass certain
 * stream buffering operations
 * in higher-level I/O functions.
 *
 * Return: Returns 1 on successful writing of the character.
 * If there is an error during the write operation, the function returns -1,
 * with 'errno' set to indicate the specific error encountered by the
 * 'write' system call.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

