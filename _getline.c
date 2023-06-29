#include "shell.h"

/**
  * _getline - stores command into buffer
  * @str: buffer
  * Return: characters used
  */

size_t _getline(char **str)
{
	ssize_t i = 0;
	size_t size = 0, t = 0, n;
	char buf[1024];
	char *temp;

	while (t == 0 && (i = read(STDIN_FILENO, buf, sizeof(buf) - 1)) > 0)
	{
		if (i == -1)
			return (-1);

		buf[i] = '\0';

		n = 0;

		while (buf[n] != '\0')
		{
			if (buf[n] == '\n')
				t = 1;
			n++;
		}

		if (*str == NULL)
		{
			*str = malloc(sizeof(char) * (i + 1));
			if (*str == NULL)
				return (-1);

			_strcpy(*str, buf);
			size = i;
		}

		else
		{
			temp = realloc(*str, sizeof(char) * (size + i + 1));
			if (temp == NULL)
			{
				free(*str);
				return (-1);
			}

			*str = temp;
			_strcat(*str, buf);
			size += i;
		}
	}

	return (size);
}
