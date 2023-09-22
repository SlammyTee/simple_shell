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
	char *buffer, *buf, ch = 0;
	int i, size = 1024, rd;

	buffer = malloc(size);
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	for (i = 0; ch != EOF && ch != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &ch, 1);
		if (rd == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[i] = ch;
		if (buffer[0] == '\n')
			return (empty(buffer));
		if (i >= size)
		{
			buffer = realloc(buffer, (size + 2));
			if (buffer == NULL)
			{
				free(buffer);
				return (NULL);
			}
		}
	}
	buffer[i] = '\0';
	buf = remove_space(buffer);
	return (buf);
}

/**
 * empty - handles an empty string with a newline character
 * @input: string input
 * Return: empty string
 */

char *empty(char *input)
{
	free(input);
	return ("\0");
}

/**
 * remove_space - removes white or empty spaces
 * @input: string input
 * Return: input without preceeding white spaces
 */

char *remove_space(char *input)
{
	int i, j = 0;
	char *buffer;

	buffer = malloc(sizeof(char) * (str_len(input) + 1));
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	for (i = 0; input[i] == ' '; i++)
	{
	}
	for (; input[i + 1] != '\0'; i++)
	{
		buffer[j] = input[i];
		j++;
	}
	buffer[j] = '\0';
	if (buffer[0] == '\0' || buffer[0] == '#')
	{
		free(buffer);
		return ("\0");
	}
	return (buffer);
}


/**
 * hashSign - removes everything after the # sign
 * @input: string input
 */

void hashSign(char *input)
{
	int i;

	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == '#' && input[i - 1] == ' ' && input[i + 1] == ' ')
		{
			input[i] = '\0';
		}
	}
}


