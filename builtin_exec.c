#include "main.h"

/**
 * is_builtin - checks if a command is a built in command
 * @cmd: command input
 * Return: 2 if builtin, 0 otherwise
 */
int is_builtin(char **cmd)
{
	int i;
	char *builtin_cmds[] = {
		"cd",
		"exit",
		"env",
		"setenv",
		"unsetenv"};

	for (i = 0; i < 5; i++)
	{
		if (strcmp(cmd[0], builtin_cmds[i]) == 0)
		{
			return (2);
		}
	}

	return (0);
}


/**
 * exec_builtin - executes a builtin command
 * @cmd: command input
 */
void exec_builtin(char **cmd)
{
	int i, match = 0;
	char *builtin_cmds[] = {
		"cd",
		"exit",
		"env",
		"setenv",
		"unsetenv"};

	for (i = 0; i < 5; i++)
	{
		if (strcmp(cmd[0], builtin_cmds[i]) == 0)
		{
			match = i + 1;
			break;
		}
	}

	if (match == 1)
	{
		cd_def(cmd[1]);
	}
	else if (match == 2)
	{
		exit(EXIT_SUCCESS);
	}
	else if (match == 3)
	{
		get_env();
	}
	else if (match == 4)
	{
		_setenv(cmd[1], cmd[2]);

	}
	else if (match == 5)
	{
		_unsetenv(cmd[1]);
	}
}
