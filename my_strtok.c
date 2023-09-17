#include "main.h"
/**
*str_tok - tokenizes a string input and returns 
*a substring to the calling function
*@str1: string input to be tokenized 
*/

char *str_tok(char *str1 , char *str2)
{
	char *temp_str;
	char *sub_str;
	char *delim_ptr = strchr(str1 , DELIM);
	if (*delim_ptr == DELIM)
		*delim_ptr = '\0';
	temp_str = str1;
	sub_str = temp_str;
	delim_ptr++;
	str1 = delim_ptr;
	return sub_str;
}
