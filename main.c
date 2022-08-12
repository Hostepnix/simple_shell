#include "shell.h"

/**
 * main - Command-line interpreter
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0 (Success process)
 *
 * Authors: Monica Ortiz - Abdel Mejia
 */
int main(__attribute__((unused))int argc, __attribute__((unused)) char *argv[])
{
	char *buffer = NULL;
	size_t buff_size = 0;
	ssize_t line = 0;

	if (!isatty(0))
	{
		line = getline(&buffer, &buff_size, stdin);
		process(buffer);
	}
	else
	{
		do {
			prompt();
			line = getline(&buffer, &buff_size, stdin);

			if (line == EOF)
			{
				free(buffer);
				_putchar('\n');
				return (EXIT_SUCCESS);
			}

			process(buffer);
		} while (line != EOF);
	}

	return (EXIT_SUCCESS);
}
