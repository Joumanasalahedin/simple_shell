#include "shell.h"

/**
  * main - starts the shell program
  * @ac: argument count
  * @av: argument vectors
  * @env: env variables
  * Return: 0
  */

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	return (run_shell(env));
}
