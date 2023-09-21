#include "main.h"

/**
 * main - execute the whole program
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variable
 * Return: 0 on success
 */


int main(int argc, char **argv, char **env)
{
	char *str;
	char **cmd;
	int status;

	(void) argc;
	(void) argv;

	while (1)
	{
		print_prompt();
		str = read_input();
		cmd = split_str(str);
		status = is_builtin(cmd);
		if (status == 0)
		{
			simple_exec(cmd, env);
		}
		else
			exec_builtin(cmd);
	}

	free(str);
	free(cmd);
	return (0);
}
