#include "shell.h"

/**
  * run_shell - prompts user and executes commands
  * @environ: environmental variables
  * Return: 0
  */

int run_shell(char **environ)
{
	list_t *env = list_env(environ);
	size_t line_no = 0, i, n;
	int exit_stat = 0;
	char *command, *n_command;
	char **token;

	while (1)
	{
		line_no++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		else
			non_interactive(env);

		signal(SIGINT, ctrl_c);

		command = NULL;
		i = _getline(&command);

		ctrl_d(i, command, env);

		n_command = command;
		command = ignore_space(command);
		n = 0;

		while (command[n] != '\n')
			n++;
		command[n] = '\0';

		if (command[0] == '\0')
		{
			free(n_command);
			continue;
		}

		token = _strtok(command, " ");
		free(n_command);

		exit_stat = builtin(token, env, line_no, NULL);
		if (exit_stat)
			break;

		exit_stat = execute(token, env, line_no);
	}

	return (exit_stat);
}
