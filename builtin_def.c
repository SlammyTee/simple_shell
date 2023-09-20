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
		chdir("$HOME");
	}
	else if (strcmp(dir, "-") == 0)
	{
		prev = getcwd(buffer, 1024);
		chdir(prev);
	}
	else
	{
		if (chdir(dir) != 0)
		{
			perror("Error: couldn't cd into directory\n");
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

