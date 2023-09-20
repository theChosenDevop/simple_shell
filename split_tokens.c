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

	token = _strtok(lineptr, delim);
	while (token != NULL)
	{
		argv[i++] = _strdup(token);
		token = _strtok(NULL, delim);
	}
	argv[i] = NULL;
}

/**
 * _strtok - tokenize strings
 * @string: input
 * @del: delimiter
 * Return: pointer to the next token
 */

char *_strtok(char *string, const char *del)
{
	static char *tok;

	char *new_token = NULL;

	if (string != NULL)
		tok = string;
	if (tok == NULL || *tok == '\0')
		return (NULL);
	while (*tok != '\0' && compare_str_delim(*tok, del))
		tok++;
	if (*tok == '\0')
		return (NULL);

	new_token = tok;

	while (*tok != '\0' && !compare_str_delim(*tok, del))
		tok++;
	if (*tok != '\0')
	{
		*tok = '\0';
		tok++;
	}

	return (new_token);
}

/**
 * compare_str_delim - checks if the delimiter and character match
 * @a: input to check
 * @del: characters to compare
 * Return: 1 on success, 0 on failure
 */
unsigned int compare_str_delim(char a, const char *del)
{
	while (*del != '\0')
	{
		if (*del == a)
			return (1);
		del++;
	}
	return (0);
}
