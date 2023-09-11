#include "main.h"

/**
 * simple_exec - executes simple commands
 * @cmd: command to be executed
 */

void simple_exec(char **cmd)
{	
	pid_t pid;
	int status;
	char *full_str;
	full_str = "usr/bin/";
	pid = fork();
	if (pid == 0)
	{	
		strcat(full_str,cmd[0]);
		if (execve(full_str ,cmd ,NULL) == -1)
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

