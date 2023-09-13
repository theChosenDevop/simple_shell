#include "shell.h"
/**
 * _strncmp - compare two strings
 * @str1: first string input
 * @str2: second string input
 * @n: input
 * Return: output
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}

		if (*str1 == '\0')
		{
			return (0);
		}
		str1++;
		str2++;
		n--;
	}
	return (0);
}

/**
 * _strchr - location first occurrence of i
 * @s: input
 * @c: input
 * Return: value
 */
char *_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	return (NULL);
}


