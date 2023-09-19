#include "main.h"

/**
*str_tok - tokenizes a string input and returns 
*a substring to the calling function
*@str1: string input to be tokenized 
*/

char *str_tok(char *str1)
{
	char *token_ptr;
	char str_arr[20];
	char token[10];
	int i , len = strlen(str1);
	for (i = 0 ; i <= len; i++){
		if ( *str1 == ' ' ){
			continue;
		}else{	
		str_arr[i] = *str1;
		str1++;
		}
	}
	for(i = 0 ; i <= len ; i++){
		if (str_arr[i] == ' ' || str_arr[i] == '\n' || str_arr[i] == '|'){
			//str_arr[i] = NULL;
			break;
		}else{
			token[i] = str_arr[i];
		}
	}
	token_ptr = token;
	str = str + strlen(token) + 1;
	return token_ptr;
}
