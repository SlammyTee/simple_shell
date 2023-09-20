#include "main.h"

/**
 * find_path - Find the path of a command
 * @cmd: command input
 * Return: NULL if the command is not found, else path
 */
char *find_path(char *cmd)
{
	char *copy, *token;
	char full_path[1024];
	char *path = getenv("PATH");

	if (path == NULL)
	{
		perror("Error");
		return (NULL);
	}

	copy = strdup(path);
	if (copy == NULL)
	{
		perror("Error");
		return (NULL);
	}

	token = strtok(copy, ":");
	while (token != NULL)
	{
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, cmd);
		strcat(full_path, "\0");

		if (access(full_path, F_OK) == 0)
		{
			free(copy);
			return (strdup(full_path));
		}
		token = strtok(NULL, ":");
	}
	free(copy);
	return (NULL);
}
