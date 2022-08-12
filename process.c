#include "shell.h"

/**
 * msg - message handler
 * @sig: signal
 *
 * Return void
 */
void msg(int sig)
{
	if (sig == SIGINT)
	{
		_putchar('\n');
		prompt();
	}
}

/**
 * process - New process and execute
 * @buffer: string allocade by buffer
 *
 * Return: void
 */
void process(char *buffer)
{
	pid_t child_id;
	char **prts;

	prts = str_to_arrays(buffer);
	child_id = fork();
	if (child_id == -1)
	{
		msgerr("Failed to create new process", 1);
	}
	else if (child_id == 0)
	{
		if (execve(prts[0], prts, environ) == -1)
		{
			msgerr("Failed to execute the process", 1);
		}
	}
	else
	{
		wait(NULL);
		signal(SIGINT, msg);
	}
}
