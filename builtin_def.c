#include "main.h"

/**
 * cd_def - changes directory
 * @dir: given directory to change to
 */
void cd_def(char *dir)
{
	char *prev = NULL;

	if (dir == NULL)
	{
		chdir("$HOME");
	}
	else if (strcmp(dir, "-") == 0)
	{
		prev = getcwd(prev, 0);
		chdir(prev);
	}
	else
	{
		if (chdir(dir) != 0)
		{
			perror("Error: Error when changing directory to PATH.");
		}
	}
}

/**
 * get_env - prints environment variables
 */

void get_env(void)
{
	char *var;
	int i = 0;

	var = environ[i];
	while (var)
	{
		printf("%s\n", var);
		i++;
		var = environ[i];
	}
}
