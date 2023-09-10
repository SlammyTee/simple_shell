#include "main.h"

/**
 * simple_exec - executes simple commands
 * @cmd: command to be executed
 */

void simple_exec(char **cmd)
{	
	pid_t pid;
	int status;
	char *envp[] = {"PATH=/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin",NULL};
	pid = fork();
	if (pid == 0)
	{
		if (execve(getFullPath(cmd),cmd,envp) == -1)
		{
			perror("Error");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Error");
	}
	else 
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

}

