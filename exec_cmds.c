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

void exec_piped(char **cmd)
{
	int fd[2];
	pid_t p1;

	pipe(fd);

	p1 = fork();
	if (p1 == -1)
	{
		perror("forking failed");
		exit(EXIT_FAILURE);
	}
	else if (p1 == 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		if (execvp(cmd[0], cmd) == -1)
		{
			perror("Error");
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], 1);
		if (execvp(cmd[3], cmd) == -1)
		{
			perror("Error");
		}
		exit(EXIT_FAILURE);
	}

}
