#include "shell.h"

/**
 * my_getenv - get path of environmant variable
 * @path: input
 * Return: path
 */
char *my_getenv(const char *path)
{
	char **env;
	unsigned int len;

	len = _strlen(path);
	env = environ;
	for (; *env != NULL; env++)
	{
		if (_strncmp(*env, path, len) == 0 && (*env)[len] == '=')
		{
			return (*env + len + 1);
		}
	}
	return (NULL);
}
