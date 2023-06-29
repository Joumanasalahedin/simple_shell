#include "shell.h"

/**
  * token_length - returns token's length
  * @input: a token
  * @position: index position
  * @delim:
  * Return: token length
  */

int token_length(char *input, int position, char delim)
{
	int length = 0;

	while ((input[position] != delim) && (input[position] != '\0'))
	{
		position++;
		length++;
	}

	return (length);
}

/**
  * count_delim - returns number of delimiters
  * @input: user's command
  * @delim: delimiter
  * Return: number of delimiters
  */

int count_delim(char *input, char delim)
{
	int index = 0, num_delim = 0;

	while (input[index] != '\0')
	{
		if ((input[index] == delim) && (input[index + 1] != delim))
		{
			num_delim++;
		}

		if ((input[index] == delim) && (input[index + 1] == '\0'))
		{
			num_delim--;
		}
		index++;
	}

	return (num_delim);
}

/**
  * ignore_delim - returns string without delims
  * @str: string
  * @delim: delimiter
  * Return: new string
  */

char *ignore_delim(char *str, char delim)
{
	while (*str == delim)
	{
		str++;
	}

	return (str);
}

/**
  * _strtok - breaks string str into a series of tokens
  * @str: string
  * @delim: delimiters
  * Return: pointer
  */

char **_strtok(char *str, char *delim)
{
	int bufsize = 0, pos = 0, si = 0, index = 0, len = 0, se = 0, t = 0;
	char **toks = NULL, delim_ch;

	delim_ch = delim[0];

	str = ignore_delim(str, delim_ch);
	bufsize = count_delim(str, delim_ch);

	toks = malloc(sizeof(char *) * (bufsize + 2));

	if (toks == NULL)
		return (NULL);
	while (str[se] != '\0')
		se++;
	while (si < se)
	{
		if (str[si] != delim_ch)
		{
			len = token_length(str, si, delim_ch);
			toks[pos] = malloc(sizeof(char) * (length + 1));
			if (toks[pos] == NULL)
				return (NULL);
			index = 0;

			while ((str[si] != delim_ch) && (str[si] != '\0'))
			{
				toks[pos][index] = str[si];
				index++;
				si++;
			}

			toks[pos][index] = '\0';
			t++;
		}

		if (si < se && (str[si + 1] != delim_ch && str[si + 1] != '\0'))
			pos++;
		si++;
	}

	pos++;
	toks[pos] = NULL;
	return (toks);
}
