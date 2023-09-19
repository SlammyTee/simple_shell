#include "main.h"

/**
 * main - execute the whole program
 * Return: 0 on success
 */


int main(void)
{
	char *str1;
	char **cmd;
	int status;

	while (1)
	{
		print_prompt();
		str1 = read_input();
		cmd = split_str(str1);

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
