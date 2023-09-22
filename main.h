#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define DELIM " \n"
extern char **environ;
extern char *st;

char *read_input(void);
void print_prompt(void);
char **split_str(char *str);
void simple_exec(char **cmd, char **env);
char *replace_newline(char *line);
void cd_def(char *dir);
void get_env(void);
int is_builtin(char **cmd);
void exec_builtin(char **cmd);
int _unsetenv(const char *name);
int _setenv(const char *name, const char *value);
char *find_path(char **cmd);
void replace_env(char *var);
int str_len(char *str);
char *str_cpy(char *dest, char *src);
char *str_cat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *empty(char *input);
char *remove_space(char *input);
void hashSign(char *input);

#endif
