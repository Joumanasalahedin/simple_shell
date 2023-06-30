#include "shell.h"

/**
  * run_shell - prompts user and executes commands
  * @environ: environmental variables
  * Return: 0
  */

int run_shell(char **environ)
{
	list_t *env;
	size_t i = 0, n = 0;
	int line_no = 0, exit_stat = 0;
	char *command, *n_command;
	char **token;

	env = list_env(environ);
	do
	{
		line_no++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		else
			non_interactive(env);
		signal(SIGINT, ctrl_c);
		command = NULL;
		i = 0;
		i = _getline(&command);
		ctrl_d(i, command, env);
		n_command = command;
		command = ignore_spaces(command);
		n = 0;
		while (command[n] != '\n')
			n++;
		command[n] = '\0';
		if (command[0] == '\0')
		{
			free(n_command);
			continue;
		}
		token = NULL;
		token = _strtok(command, " ");
		if (n_command != NULL)
			free(n_command);
		exit_stat = builtin_c(token, env, line_no, NULL);
		if (exit_stat)
			continue;
		exit_stat = execute(token, env, line_no);
	} while (1);
	return (exit_stat);
}
