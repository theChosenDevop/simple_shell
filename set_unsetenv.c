#include "shell.h"

/**
* check_setenv - set environment variables
* @args: argument vector
* Return: void
*/
void check_setenv(char **args)
{
	char msg[] = "Message: setenv value \n";

	if (*(args + 1) != NULL && *(args + 2) != NULL)
	{
		if (setenv(*(args + 1), *(args + 2), 1) != 0)
		{
			perror("setenv");
		}
	}
	else
	{
		write(STDERR_FILENO, msg, _strlen(msg));
	}
}

/**
* check_unsetenv - unset environment variables
* @args: argument vector
* Return: void
*/
void check_unsetenv(char **args)
{
	char msg[] =  "Message: unsetenv value \n";

	if (*(args + 1) != NULL)
	{
		if (unsetenv(*(args + 1)) != 0)
			perror("unsetenv");
	}
	else
	{
		write(STDERR_FILENO, msg, _strlen(msg));
	}
}
