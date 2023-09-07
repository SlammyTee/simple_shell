#include "main.h"

/**
 * print_prompt - function displays the prompt to the terminal
 *
 */

void print_prompt(void)
{
	char *prompt = "$ ";

	printf("%s", prompt);
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

		printf("%s\n", "exiting shell");
		exit(EXIT_SUCCESS);
	}

	return (buffer);
}
