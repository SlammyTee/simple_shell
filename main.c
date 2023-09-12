#include "main.h"

/**
 * main - execute the whole program
 * Return: 0 on success
 */

int main(void)
{
	char *str;
	char **cmd;

	while (1)
	{
		print_prompt();
		str = read_input();
		cmd = split_str(str);
	/*	simple_exec(cmd);*/


	}

	free(str);
	free(cmd);
	return (0);
}
