#include "shell.h"

/**
 * split_line_tokens - split user inputs into tokens
 * @lineptr: input
 * @argv: input
 * Return: void
 */
void split_line_tokens(char *lineptr, char **argv)
{
	char *token;
	const char *delim = " \n\t";
	int i = 0;

	token = strtok(lineptr, delim);
	while (token != NULL)
	{
		argv[i++] = _strdup(token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
}
