#include "shell.h"

/**
  * _strtok - breaks string str into a series of tokens
  * @str: string
  * @delim: delimiters
  * Return: pointer
  */

char *_strtok(char *str, const char *delim)
{
	static char *current;
	char *start;
	const char *delim_ptr;

	if (str)
		current = str;
	if (!current)
		return (NULL);

	start = current;

	while (*current != '\0')
	{
		delim_ptr = delim;

		while (*delim_ptr != '\0')
		{
			if (*current == *delim_ptr)
			{
				*current = '\0';
				current++;
				if (*current == '\0')
				{
					current = NULL;
				}
				return (start);
			}
			delim_ptr++;
		}
		current++;
	}

	if (start == current)
		return (NULL);

	return (start);
}
