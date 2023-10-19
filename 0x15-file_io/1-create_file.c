#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - Create a file and write content to it.
 * @filename: The name of the file to be created.
 * @text_content: The content to be written to the file.
 *
 * Return: On success, return 1. On failure, return -1.
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor, write_result, content_length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[content_length])
			content_length++;
	}

	file_descriptor = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	write_result = write(file_descriptor, text_content, content_length);

	if (file_descriptor == -1 || write_result == -1)
		return (-1);

	close(file_descriptor);

	return (1);
}

