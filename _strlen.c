#include "shell.h"

/**
 * _strlen - function that returns the length of a string.
 * @s: string
 *
 * Return: length of string
 */

int _strlen(char *s)
{
	int len = 0;

	if (s == NULL)
	{
		return (-1);
	}
	for (; *s++;)

		len++;
	return (len);
}
