#include "shell.h"

/**
 * main - entry point
 * @ac: argument count
 * @av: argumet vector
 * @env: environment variable
 * Return: 0 always
 */
int main(int ac, char **av, char **env)
{
	ssize_t readinput = 0;
	char *path = NULL, *lineptr = NULL, *argv[10];
	int mode = isatty(0);
	(void)ac, (void)env;

	signal(SIGINT, handle_signal);
	while (1)
	{
		if (mode == 1)
		{write(STDOUT_FILENO, "$ ", 2); }
		readinput = getline(&lineptr, &n, stdin);
		if (readinput == -1)
		{
			free(lineptr);
			exit(0);
		}
		lineptr[readinput - 1] = '\0';
		split_line_tokens(lineptr, argv);
		execute_command(av, path. argv, env);
		free_tokens(argv);
		free(lineptr);
	}
	return (0);
}

/**
 * free_tokens - free array pointer tokens
 * @tokens: input
 * Return: void
 */

void free_tokens(char **tokens)
{
	int i;

	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
}

/**
 * execute_command - execute user inputs as commands
 * @av: argument vector
 * @argv: argumet vector
 * @env: environment variable
 * Return: 0 always
 */
int execute_command(char **av, char *path. char **argv, char **env)
{
	pid_t child_pid;
	int status, val;

	status = 0;

	child_pid = fork();
	if (child_pid < 0)
	{
		perror(av[0]);
		exit(1);
	}
	else if (child_pid == 0)
	{
		val = execve(path, argv, env);
		if (val == -1)
		{
			perror("execve");
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
