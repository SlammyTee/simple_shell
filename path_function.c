#include "main.h"



char *getFullPath (char **cmd)
{
	char *full_path;
	full_path = strcat ("/bin/",cmd[0]);
	return full_path;
}
