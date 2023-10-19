#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *output_file);
void close_fd(int file_desc);

/**
 * create_buffer - Allocates a 1024-byte buffer.
 * @output_file: The name of the file where buffer content will be written.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *output_file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", output_file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_fd - Closes file descriptors.
 * @file_desc: The file descriptor to be closed.
 */
void close_fd(int file_desc)
{
	int result;

	result = close(file_desc);

	if (result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_desc);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect, exit with code 97.
 * If source_file does not exist or cannot be read, exit with code 98.
 * If destination_file cannot be created or written to, exit with code 99.
 * If source_file or destination_file cannot be closed, exit with code 100.
 */
int main(int argc, char *argv[])
{
	int src_fd, dest_fd, bytes_read, bytes_written;
	char *copy_buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	copy_buffer = create_buffer(argv[2]);
	src_fd = open(argv[1], O_RDONLY);
	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do

	{
		bytes_read = read(src_fd, copy_buffer, 1024);
		bytes_written = write(dest_fd, copy_buffer, bytes_read);

		if (src_fd == -1 || bytes_read == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(copy_buffer);
			exit(98);
		}

		if (dest_fd == -1 || bytes_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(copy_buffer);
			exit(99);
		}

	} while (bytes_read > 0);

	free(copy_buffer);
	close_fd(src_fd);
	close_fd(dest_fd);

	return (0);
}

