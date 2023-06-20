#include "shell.h"

/**
  * _getline - reads a string
  * Return: pointer
  */

char *_getline(void)
{
	static char buffer[BUFSIZE];
	static size_t buffer_index;
	static ssize_t chars_remain;
	char *line = NULL;
	size_t line_length = 0;

	while (1)
	{
		if (buffer_index >= (size_t)chars_remain)
		{
			chars_remain = read(STDIN_FILENO, buffer, BUFSIZE);
			if (chars_remain <= 0)
			{
				free(line);
				line = NULL;
			}
			buffer_index = 0;
		}

		if (buffer[buffer_index] == '\n' || buffer[buffer_index] == '\0')
		{
			buffer_index++;
			break;
		}

		line = (char *)realloc(line, line_length + 1);
		line[line_length] = buffer[buffer_index];
		line_length++;
		buffer_index++;
	}

	line = (char *)realloc(line, line_length + 1);
	line[line_length] = '\0';

	return (line);
}
