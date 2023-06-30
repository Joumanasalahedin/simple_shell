#include "shell.h"

/**
 * _strcpy - copy the string pointed by src to dest
 * @src: char
 * @dest: char
 *
 * Return: 0.
 */

char *_strcpy(char *dest, char *src)
{
	int j, length;

	for (length = 0; src[length] != '\0'; length++)
	{
		;
	}

	for (j = 0; j <= length; j++)
		dest[j] = src[j];

	return (dest);
}
