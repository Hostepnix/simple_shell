#ifndef SHELL_H
#define SHELL_H

/* include library */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

/* Variables  */
extern char **environ;

/* putchar prototype */
int _putchar(char c);

/* Strings */
char *_strdup(char *str);

/* Shell */
void prompt(void);
void process(char *buffer);
char **str_to_arrays(char *buffer_str);

/* Util */
void msgerr(const char *str, int status);

#endif
