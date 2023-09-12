#include "main.h"

/**
 * main - execute the whole program
 * Return: 0 on success
 */

int main(void)
{
	char *str;
	char **cmd;
	int status;

	while (1)
	{
		print_prompt();
		str = read_input();
		cmd = split_str(str);
/*		simple_exec(cmd); */
		status = is_pipe(cmd);
		if (status == 1)
			exec_piped(cmd);
		else
			simple_exec(cmd);



	}

	free(str);
	free(cmd);
	return (0);
}
