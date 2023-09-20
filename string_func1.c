#include "main.h"

/**
* str_len - function to find the length of a string
* @str: string to find its length 
* Returns: an integer value is returned to the calling function 
*/
int str_len(char *str)
{
        int i;
        for(i = 0;*str != NULL;i++)
        {
                str++;
        }
        return (i);
}
