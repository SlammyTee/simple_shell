#include "main.h"

/**
 * main - execute the whole program
 * Return: 0 on success
 */


int main(void)
{
	char **cmd;
	int status;

	while (1)
	{
		print_prompt();
		st = read_input();
		cmd = split_str(st);

		status = is_builtin(cmd);
		if (status == 0)
		{
			simple_exec(cmd);
		}
		else
			exec_builtin(cmd);
	}

	free(st);
	free(cmd);
	return (0);
}
