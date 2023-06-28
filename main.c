#include "shell.h"

/**
  * main - entry point
  * @argc: count
  * @argv: vector
  * Return: 0
  */

int main(int argc, char *argv[])
{
	(void) argc;
	(void) argv[0];

	if (isatty(STDIN_FILENO) == 1)
	{
		while (1)
		{
			shell_read_line();
		}
	}
	return (0);
}
