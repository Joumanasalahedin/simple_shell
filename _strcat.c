#include "shell.h"

/**
 * _strcat -  a function that concatenates two strings.
 * @dest: char
 * @src: char
 *
 * Return: char
 */

char *_strcat(char *dest, char *src)
{
	int len = 0, len2 = 0, total = 0, j = 0;

	while (dest[len] != '\0')
	{
		len++;
		total++;
	}

	while (src[len2] != '\0')
	{
		len2++;
		total++;
	}

	dest = re_alloc(dest, len, sizeof(char) * total + 1);

	while (src[j] != '\0')
	{
		dest[len] = src[j];
		len++;
		j++;
	}

	dest[len] = '\0';
	return (dest);
}
