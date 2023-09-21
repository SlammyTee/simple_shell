#include "main.h"

/**
 * cd_def - changes directory
 * @dir: given directory to change to
 */
void cd_def(char *dir)
{
	char *prev, buffer[1024];


	if (dir == NULL)
	{
		chdir(getenv("HOME"));
	}
	else if (strcmp(dir, "-") == 0)
	{
		prev = getenv("OLDPWD");
		chdir(prev);
	}
	else
	{
		if (chdir(dir) != 0)
		{
			perror("Error: couldn't cd into directory\n");
			exit(EXIT_FAILURE);
		}
		getcwd(buffer, sizeof(buffer));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", buffer, 1);


	}
}

/**
 * get_env - prints environment variables
 */

void get_env(void)
{
	char *var;
	int i = 0, len;

	var = environ[i];
	while (var)
	{
		len = strlen(var);
		write(1, var, len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
		var = environ[i];
	}
}

/**
 * _setenv - sets / creates / replaces environment variable
 * @name: environment variable name
 * @value: value of environment variable
 * Return: 0 on success , -1 on failure
 */

int _setenv(const char *name, const char *value)
{
	char *var;
	int i = 0;

	if (name == NULL || name[0] == '\0' ||
			strchr(name, '=') != NULL || value == NULL)
	{
		fprintf(stderr, "%s", "error expected 2 arguments\n");
		return (-1);
	}
	var = (char *)malloc(strlen(name) + strlen(value) + 2);
	if (var == NULL)
	{
		fprintf(stderr, "%s\n", "memory allocation failure");
		return (-1);
	}

	strcpy(var, name);
	strcat(var, "=");
	strcat(var, value);
	if (getenv(name))
	{
		replace_env(var);
	}
	else
	{
		while (environ[i])
		{
			i++;
		}
		environ[i] = var;
		environ[i + 1] = NULL;
	}

	return (0);
}

/**
 * replace_env - replaces an existing environment variable
 * @var: variable formatted
 */

void replace_env(char *var)
{
	if (putenv(var) != 0)
	{
		fprintf(stderr, "%s\n", "Error: setting environment variable failure");
	}
}


/**
 * _unsetenv - unsets / deletes environment variable
 * @name: environment variable name
 * Return: 0 on success , -1 on failure
 */
int _unsetenv(const char *name)
{
	int i, r;

	if (name)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			if (strcmp(environ[i], name) == 0 && environ[i][strlen(name)] == '=')
			{
				free(environ[i]);
				for (r = i; environ[r] != NULL; r++)
				{
					environ[r] = environ[r + 1];
				}
				i++;
			}
			environ[r] = NULL;
			return (0);
		}
	}

	fprintf(stderr, "%s\n", "failed to unset variable");
	return (-1);
}
