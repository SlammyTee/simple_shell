#include "main.h"

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

