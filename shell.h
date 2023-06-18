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

char *shell_read_line(void);
int execute(char *command);

/* helper functions */
int _strcmp(char *s1, char *s2);

#endif /* SHELL_H */
