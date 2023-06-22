#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

#define TOK_DELIM " \t\n"
#define BUFSIZE 64
extern char **environ;

char *get_path(char *command);
int command_args(char *command);
char **shell_split_line(char *command);
char *shell_read_line(void);
int execute(char **args);
char *_getline(void);
int sh_cd(char **args);
int sh_exit(void);
int sh_env(char **args);
int sh_help(char **args);

/* helper functions */
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strtok(char *str, const char *delim);

#endif /* SHELL_H */
