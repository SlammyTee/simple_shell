#include "main.h"

/**
 * simple_exec - executes simple commands
 * @cmd: command to be executed
 */

void simple_exec(char **cmd)
{
	char *path;

	if (cmd)
	{
		path = find_path(cmd[0]);
		if (execve(path, cmd, NULL) == -1)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
	}
	exit(EXIT_FAILURE);
}

