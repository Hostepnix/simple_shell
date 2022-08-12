#include "shell.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: duplicate of the string
 *
 * Return: Address of the array
 */
char *_strdup(char *str)
{
	int i, a;
	char *m;

	if (str == '\0')
	{
		return ('\0');
	}
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	m = malloc((i * sizeof(char)) + 1);
	if (m == '\0')
	{
		return ('\0');
	}
	for (a = 0; a < i; a++)
	{
		m[a] = str[a];
	}
	m[a] = '\0';

	return (m);
}
