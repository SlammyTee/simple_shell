#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define DELIM " \n\""


char *read_input(void);
void print_prompt(void);
char **split_str(char *str);
void simple_exec(char **cmd);
char *getFullPath(char **cmd);
int is_pipe(char **cmd);
void exec_piped(char **cmd);

#endif
