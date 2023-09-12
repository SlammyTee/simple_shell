#include "main.h"

/**
 * simple_exec - executes simple commands
 * @cmd: command to be executed
 */

void simple_exec(char **cmd)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("forking failed");
	}

	else if (pid == 0)
	{
		if (execvp(cmd[0], cmd) == -1)
		{
			perror("Error");
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
		return;
	}
}

/**
 * exec_piped - executes piped commands
 * @cmd: command input
 */
/*void exec_piped(char **cmd)*/
/*{ */
/*	int pipefd[2]; */
/*	pid_t p1, p2;*/

/*} */


