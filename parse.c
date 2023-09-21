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


