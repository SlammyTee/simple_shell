#include "main.h"

/**
 * str_len - function to find the length of a string
 * @str: string to find its length
 * Return: an integer value is returned to the calling function
 */
int str_len(char *str)
{
	int i;

	for (i = 0; str != NULL; i++)
	{
		str++;
	}
	return (i);
}
/**
 * str_cpy - function to copy the string pointed to by src
 * to the string pointed to by dest.
 * @dest: A pointer to destination of string
 * @src: A pointer to source string to copy from
 * Return: pointer to destination string
 */
char *str_cpy(char *dest, char *src)
{
	char *aux = dest;

	while (*src)
		*dest++ = *src++;
	return (aux);
}

/**
 * str_cat - function to concatenates two strings.
 * @dest: a string input
 * @src: a string input
 * Return: A pointer to the result string
 */
char *str_cat(char *dest, char *src)
{
	char *temp = dest;

	while (*dest)
		dest++;

	while (*src)
		*dest++ = *src++;

	*dest = '\0';
	return (temp);
}
