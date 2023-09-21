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
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);

}

/**
 * str_cat - concatenates two strings.
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


/**
 * _strcmp - compares two string
 * @s1: first string input
 * @s2: second string input
 * Return: 0 if same , 1 otherwise
 */
int _strcmp(char *s1, char *s2)
{
	int cmp = 0, i, len1, len2;

	len1 = str_len(s1);
	len2 = str_len(s2);

	if (s1 == NULL || s2 == NULL)
		return (1);

	if (len1 != len2)
		return (1);

	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			cmp = s1[i] - s2[i];
			break;
		}
		else
			continue;

	}
	return (cmp);
}


