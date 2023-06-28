#include "shell.h"

/**
  * main - entry point
  * Return: 0
  */

int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		while (1)
		{
			shell_read_line();
		}
	}
	return (0);
}
