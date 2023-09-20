#include "main.h"

/**
 * split_str - split the string input into words
 * @str: string input entered in terminal / stdin
 * Return: parsed words / commands
 */

char **split_str(char *str)
{
	char **parsed;
	char *tokens;
	int i = 0, len = 0;

	len = strlen(str);
	parsed = malloc(sizeof(char *) * len);
	if (parsed == NULL)
	{
		perror("tsh: memory allocation error");
		exit(EXIT_FAILURE);
	}
	tokens = strtok(str, DELIM);

	while (tokens != NULL)
	{
		parsed[i] = tokens;
		tokens = strtok(NULL, DELIM);
		i++;

		if (i >= len)
		{
			len += 64;
			parsed = malloc(sizeof(char *) * len);
			if (parsed == NULL)
			{
				perror("tsh: memory allocation error");
				exit(EXIT_FAILURE);
			}
		}
	}
	parsed[i] = NULL;
	return (parsed);
}

/**
 * is_pipe - checks for a pipe in the parsed command string
 * @parsed: parsed command input
 * Return: index of pipe found, 0 otherwise
 */

int is_pipe(char **parsed)
{
	int i = 0;

	while (parsed)
	{
		if ((strcmp(parsed[i], "|")) == 0)
		{
			return (i);
		}
		i++;
	}
	return (0);
}

/**
 * parse_pipe - parse piped command input
 * @parsed: parsed comand input
 * @argv1: pointer to the the arguments before the pipe sign
 * @argv2: pointer to the arguments after the pipe sign
 */

void parse_pipe(char **parsed, char **argv1, char **argv2)
{
	int index, i;

	index = is_pipe(parsed);

	for (i = 0; i < index; i++)
	{
		argv1[i] = strdup(parsed[i]);
	}
	argv1[i++] = NULL;

	while (parsed[i] != NULL)
	{
		argv2[i - index] = strdup(parsed[i]);
		i++;
	}
	argv2[i - index] = NULL;
}







