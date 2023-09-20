#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define DELIM " \n\""
extern char **environ;
extern char *st;

char *read_input(void);
void print_prompt(void);
char **split_str(char *str);
void simple_exec(char **cmd);
char *getFullPath(char **cmd);
int is_pipe(char **cmd);
void exec_piped(char **cmd);
char *replace_newline(char *line);
void cd_def(char *dir);
void get_env(void);
int is_builtin(char **cmd);
void exec_builtin(char **cmd);
/*int _unsetenv(const char *name);*/
/*int _setenv(const char *name, const char *value, int overwrite);*/
char *find_path(char *cmd);
/*char *str_tok(char *str1);*/

#endif
