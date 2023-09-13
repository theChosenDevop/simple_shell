#include "shell.h"

/**
 * builtin_cmd - check inbuilt commands with user input
 * @line: input
 * @argv: input
 * Return: 0 ALways
 */
int builtin_cmd(char *line, char **argv)
{
	char *oldcwd, **env;

	if (_strcmp(argv[0], "exit") == 0)
	{free(line);
		free_tokens(argv);
		exit(0); }
	else if (_strcmp(argv[0], "env") == 0)
	{
		env = environ;
		while (*env)
		{write(STDOUT_FILENO, *env, _strlen(*env));
			write(STDOUT_FILENO, "\n", 1);
			env++; }
		return (1);
	}
	else if (_strcmp(argv[0], "cd") == 0)
	{
		oldcwd = my_getenv("PWD");
		if (argv[1] == NULL)
		{chdir(my_getenv("HOME")); }
		else if (_strcmp(argv[1], "-") == 0)
		{
			if (oldcwd != NULL)
			{chdir(oldcwd); }
		}
		else
		{
			if (chdir(argv[1]) != 0)
			{perror("cd"); }
		}
		return (1);
	}
	else if (_strcmp(argv[0], "setenv") == 0)
	{check_setenv(argv);
		return (1); }
	else if (_strcmp(argv[0], "unsetenv") == 0)
	{check_unsetenv(argv);
		return (1); }
	return (0);
}


/**
 * my_env - write to the stsndard output env
 * Return: void
 */
void my_env(void)
{
	int j = 0;

	while (environ[j] != NULL)
	{
		write(STDOUT_FILENO, environ[j], _strlen(environ[j]));
		write(STDOUT_FILENO, "\n", 1);
		j++;
	}
}

/**
 * pathFinder - environment path variable
 * @argv: input
 * Return: Path
 */
char *pathFinder(char *argv)
{
	char *path;
	char *copi_path;

	if (_strchr(argv, '/') != NULL)
		return (_strdup(argv));
	path = my_getenv("PATH");
	if (path)
	{
		copi_path = path_location(path, argv);
		if (copi_path == NULL)
		{
			return (NULL);
		}
		return (copi_path);
	}
	return (NULL);
}

/**
 * path_location - locate path
 * @path: pointer to char
 * @argv: array of pointer
 * Return: location
 */

char *path_location(char *path, char *argv)
{
	char *tok, *tokens, *temp, *delimiter = ":";
	int len = _strlen(argv);

	temp = _strdup(path);
	if (temp == NULL)
	{
		return (NULL);
	}

	tok = strtok(temp, delimiter);
	while (tok != NULL)
	{
		tokens = (char *)malloc(_strlen(tok) + len + 2);
		if (tokens == NULL)
		{
			free(temp);
			return (NULL);
		}
		_strcpy(tokens, tok);
		_strcat(tokens, "/");
		_strcat(tokens, argv);
		if (access(tokens, X_OK) == 0)
		{
			free(temp);
			return (tokens);
		}
		free(tokens);
		tok = strtok(NULL, delimiter);
	}
	free(temp);
	return (NULL);
}

/**
 * my_getenv - get path from env
 * @path: input
 * Return: path
 */

char *my_getenv(const char *path)
{
	char **env;
	unsigned int len;

	len = _strlen(path);
	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, path, len) == 0 && (*env)[len] == '=')
		{
			return (*env + len + 1);
		}
	}
	return (NULL);
}

