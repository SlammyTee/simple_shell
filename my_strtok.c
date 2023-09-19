#include "main.h"

/**
*str_tok - tokenizes a string input and returns 
*a substring to the calling function
*@str1: string input to be tokenized 
*/

char *str_tok(char *str1)
{
	char *token_ptr,
	char str_arr[20];
	char token[10];
	int i , len = strlen(str1);
	for (i = 0 ; i <= len; i++){
		str_arr[i] = *str1;
		str++;
	}
	for(i = 0 ; i <= strlen(str_arr) ; i++){
		if (str_arr[i] == ' ' || str_arr[i] == '\n' || str_arr[i] == '|'){
			str_arr[i] = NULL;
			break;
		}else{
			token[i] = str_arr[i];
		}
	}
	token_ptr = token;
	str = str + strlen(token);
	return token_ptr;
}
