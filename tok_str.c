#include "shell.h"

/**
  * c_delims - returns number of delimiters
  * @str: user's command
  * @delim: delimiter
  * Return: number of token
  */

int c_delims(char *str, char delim)
{
	int index = 0, num_delimiters = 0;
	
	while (str[index] != '\0')
	{
		if (str[index] == delim)
		{
			num_delimiters++;
		}
		index++;
	}
	return (num_delimiters);
}

/**
  * token_string - tokenizes a string
  * @str: user's command
  * @delim: delimiter
  * Return: array of tokens
  */

char **token_string(char *str, char *delim)
{
	int buffer_size = 0, position = 0, si = 0, index = 0, length = 0, se = 0;
	char **tokens = NULL, delim_char;

	delim_char = delim[0];
	buffer_size = c_delims(str, delim_char);
	tokens = malloc(sizeof(char *) * (buffer_size + 2));
	if (tokens == NULL)
		return (NULL);

	while (str[se] != '\0')
		se++;
	
	while (si < se)
	{
		length = token_length(str, si, delim_char);
		tokens[position] = malloc(sizeof(char) * (length + 1));
		
		if (tokens[position] == NULL)
			return (NULL);
		index = 0;
		
		while ((str[si] != delim_char) && (str[si] != '\0'))
		{
			tokens[position][index] = str[si];
			index++;
			si++;
		}
		
		tokens[position][index] = '\0';
		position++;
		si++;
	}
	tokens[position] = NULL;
	return (tokens);
}
