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
	int pipefd[2];
	pid_t p1, p2;
	char **parsedpipe = strtok(&cmd, "|");

	if (pipe(pipefd) < 0)
	{
		perror("pipe could not be initialized");
		return;
	}
	p1 = fork();
	if (p1 == -1)
	{
		perror("forking failed");
		return;
	}

	else if (p1 == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);

		if (execvp(cmd[0], cmd) == -1)
		{
			perror("Could not execute command 1..");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		p2 = fork();

		if (p2 == -1)
		{
			perror("forking failed");
			return;
		}

		if (p2 == 0)
		{
			close(pipefd[1]);
			dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[0]);
			if (execvp(parsedpipe[0], parsedpipe) < 0)
			{
				perror("failed to execute");
				exit(0);
			}
		}
		else
		{
			wait(NULL);
			wait(NULL);
		}
	}
}


