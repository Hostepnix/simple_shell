#include "shell.h"

/**
 * msgerr - error and exit message
 * @str: message of error
 * @status: status of error for exit
 *
 * Return: void
 */
void msgerr(const char *str, int status)
{
	perror(str);
	exit(status);
}
