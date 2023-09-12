#include "main.h"

/**
 * getFullPath - get the path of a command
 * @cmd: command input
 * Return: the path
 */

char *getFullPath(char **cmd)
{
	char *full_path;

	full_path = strcat("/bin/", cmd[0]);
	return (full_path);
} 
