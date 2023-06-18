#include "main.h"

/**
 * _strlen - function that returns the length of a string.
 * @s: string
 *
 * Return: length of string
 */

int _strlen(char *s)
{
	int len = 0;

	for (; *s++;)

		len++;
	return (len);
}
