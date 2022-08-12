#include "shell.h"

/**
 * token_num - number of words on a string
 * @str: string to split
 *
 * Return: number of words
 */
unsigned int token_num(char *str)
{
	char *token;
	char sep[] = " \n\t";
	unsigned int i = 0;

	token = strtok(str, sep);
	while (token)
	{
		token = strtok(NULL, sep);
		i++;
	}

	return (i);
}

/**
 * split_token - split a string on diferent arrays
 * @str: String to split
 * @splt_str: pointer with the memory allocated fo the strs
 * @n: number of words to split
 *
 * Return: Address of the sub-strings
 */
char **split_token(char **splt_str, char *str, unsigned int n)
{
	char *token;
	char sep[] = " \n\t";
	unsigned int j = 0;

	token = strtok(str, sep);
	while (j < n)
	{
		splt_str[j] = _strdup(token);
		if (splt_str[j] == '\0')
		{
			while (j > 0)
			{
				free(splt_str[j]);
				j--;
			}
			free(splt_str[0]);
			free(splt_str);
			free(str);
			msgerr("Failed to allocate memmory to array", 1);
		}
		token = strtok(NULL, sep);
		j++;
	}
	splt_str[j] = '\0';

	return (splt_str);
}
