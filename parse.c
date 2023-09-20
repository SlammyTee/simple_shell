#include "main.h"

/**
 * split_str - split the string input into words
 * @str: string input entered in terminal / stdin
 * Return: parsed words / commands
 */

char **split_str(char *str1)
{
	char **parsed;
	char *tokens;
	int i = 0, len = 0;

	len = strlen(str1);
	parsed = malloc(sizeof(char *) * len);
	if (parsed == NULL)
	{
		perror("tsh: memory allocation error");
		exit(EXIT_FAILURE);
	}
	tokens = strtok(str1,DELIM);

	while (tokens != NULL)
	{
		parsed[i] = tokens;
		tokens = strtok(NULL,DELIM);
		i++;

		if (i >= len)
		{
			len += 64;
			parsed = realloc(parsed, sizeof(char *) * len);
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
 * Return: 1 if pipe was found, 0 otherwise
 */

int is_pipe(char **parsed)
{
	int i = 0;

	while (parsed)
	{
		if ((strcmp(parsed[i], "|")) == 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}









