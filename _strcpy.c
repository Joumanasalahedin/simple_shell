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
	int j;

	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}

	for (j = 0; src[j] != '\0'; j++)

		dest[j] = src[j];

	dest[j] = '\0';
	return (dest);
}
