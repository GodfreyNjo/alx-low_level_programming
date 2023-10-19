#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - Append text to the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: A string to append to the end of the file.
 *
 * Return: If the function fails or filename is NULL, return -1.
 *         If the file does not exist or the user lacks write permissions,
 *         return -1.
 *         Otherwise, return 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_desc, write_result, content_length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[content_length])
			content_length++;
	}

	file_desc = open(filename, O_WRONLY | O_APPEND);
	write_result = write(file_desc, text_content, content_length);

	if (file_desc == -1 || write_result == -1)
		return (-1);

	close(file_desc);

	return (1);
}

