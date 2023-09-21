#include "main.h"

/**
 * print_prompt - function displays the prompt to the terminal
 *
 */

void print_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 3);
		fflush(stdout);
	}
}

/**
 * read_input - function reads the string input entered in the terminal
 * Return: the string read
 */

char *read_input(void)
{
	char *buffer = NULL;
	size_t size = 0;

	if (getline(&buffer, &size, stdin) == -1)
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}

	return (buffer);
}
