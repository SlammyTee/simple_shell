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
	buffer = replace_newline(buffer);

	return (buffer);
}

/**
 * replace_newline - searches for a newline character and
 * replaces it with an end of line character
 * @line: string read from the terminal
 * Return: line
 */

char *replace_newline(char *line)
{
	int i = 0;

	while (line[i] != '\n')
	{
		i++;
	}

	line[i] = '\0';

	return (line);
}

