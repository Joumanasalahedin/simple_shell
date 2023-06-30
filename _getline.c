#include "shell.h"

/**
  * _getline - stores command into buffer
  * @str: buffer
  * Return: characters used
  */

size_t _getline(char **str)
{
	ssize_t i = 0, size = 0, t1 = 0, t2 = 0, n = 0;
	char buf[1024];

	while (t2 == 0 && (i = read(STDIN_FILENO, buf, 1024 - 1)))
	{
		if (i == -1)
			return (-1);

		buf[i] = '\0';
		n = 0;
		while (buf[n] != '\0')
		{
			if (buf[n] == '\n')
				t2 = 1;
			n++;
		}
		if (t1 == 0)
		{
			i++;
			*str = malloc(sizeof(char) * i);
			*str = _strcpy(*str, buf);
			size = i;
			t1 = 1;
		}
		else
		{
			size += i;
			_strcat(*str, buf);
		}
	}
	return (size);
}
