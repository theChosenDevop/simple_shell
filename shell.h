#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <stddef.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

extern char **environ;

/** string function **/
int _strcmp(char *first, const char *sec);
char *_strcat(char *str1, char *str2);
char *_strdup(const char *src);
int _strlen(const char *s);
char *_strcpy(char *desti, const char *source);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strchr(const char *s, int c);

/* handle signal */
void handle_signal(int signum);

/** split tokens **/
void split_line_tokens(char *line, char **argv);

/** free tokens **/
void free_tokens(char **tokens);

/** excute commands **/
int exec_command(char **av, char *path, char **argv, char **env);

/** set and unset env **/
void check_setenv(char **args);
void check_unsetenv(char **args);

char *pathFinder(char *argv);
char *path_location(char *path, char *argv);
char *my_getenv(const char *path);

int builtin_cmd(char *line, char **argv);
#endif
