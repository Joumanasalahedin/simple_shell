#include "shell.h"

/**
  * sh_free_double_ptr - free malloced arrays
  * @s: string
  */

void sh_free_double_ptr(char **s)
{
	char **tmp = s;

	if (s == NULL)
	{
		return;
	}

	while (!*tmp)
	{
		free(*tmp);
		*tmp = NULL;
		tmp++;
	}

	free(s);
}
