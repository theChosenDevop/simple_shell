#include "shell.h"

/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 * @env: environment variable
 * Return: 0 Always
 */
int main(int ac, char **av, char **env)
{
	ssize_t readLine;
	size_t n = 0;
	int mode = isatty(0);
	char prompt[] = "#cisfun$ ", *path, *line = NULL, *argv[10];
	(void)ac, (void)env;

	signal(SIGINT, handle_signal);
	while (1)
	{
		if (mode == 1)
		{write(STDOUT_FILENO, &prompt, 10); }
		readLine = getline(&line, &n, stdin);
		if (readLine == -1)
		{
			/*if (mode != 1)*/
				/*write(STDOUT_FILENO, "\n", 1);*/
			free(line);
			exit(0);
		}
		line[readLine - 1] = '\0';
		split_line_tokens(line, argv);
		if (argv[0] == NULL)
		{
			continue;
		}
		if (builtin_cmd(line, argv) != 0)
		{free_tokens(argv);
			continue; }
		else
		{path = pathFinder(argv[0]);
			if (path == NULL)
			{perror(av[0]);
				free_tokens(argv);
				continue; }
			exec_command(av, path, argv, env);
		}
		free_tokens(argv);
		free(path);
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
 * exec_command - execute command
 * @av: input
 * @path: input
 * @argv: input
 * @env: input
 * Return: 0 always
 */
int exec_command(char **av, char *path, char **argv, char **env)
{
	pid_t child_pid;
	int status, ret;

	status = 0;

	child_pid = fork();
	if (child_pid < 0)
	{
		perror(av[0]);
		exit(1);
	}
	else if (child_pid == 0)
	{
		ret = execve(path, argv, env);
		if (ret == -1)
		{
			perror("test excev");
			return (2);
		}
	}
	else
	{
		wait(&status);
	}
	return (127);
}

