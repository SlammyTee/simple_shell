#include "main.h"

/**
 * main - execute the whole program
 * Return: 0 on success
 */

extern char *str;

int main(void)
{
	char **cmd;
	int status;

	while (1)
	{
		print_prompt();
		str = read_input();
		cmd = split_str(str);

		status = is_builtin(cmd);
		if (status == 0)
		{
			simple_exec(cmd);
		}
		else
			exec_builtin(cmd);
	}

	free(str);
	free(cmd);
	return (0);
}
