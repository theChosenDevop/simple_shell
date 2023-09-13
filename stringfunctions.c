#include "shell.h"
/**
 * _strlen - length of string
 * @s: parameter
 * Return: 0
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s[len] !=  '\0')
	{
		len++;
	}

	return (len);
}

/**
 * _strcpy - a fuction that copy string.
 * @desti: destination to copy to.
 * @source: source to copy from.
 * Return: desti.
 */
char *_strcpy(char *desti, const char *source)
{
	int i = 0;

	if (desti == NULL)
	{
		return (NULL);
	}


		while (source[i] != '\0')
		{
			desti[i] = source[i];
			i++;
		}
		desti[i] = '\0';
		return (desti);
}

/**
 * _strdup - makes acopy to theallocated memory
 * @src: source input
 * Return: string pointer
 */
char *_strdup(const char *src)
{
	size_t l;
	char *str;

	if (src == NULL)
	{
		return (NULL);
	}
	l  = _strlen(src);
	str = (char *)malloc(l + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	else
	{
		_strcpy(str, src);
	}

	return (str);
}

/**
 * _strcmp - compare two string.
 * @first: the first string.
 * @sec: it a constant to a string.
 * Return: 0 on success and 1 on error.
 */

int _strcmp(char *first, const char *sec)
{
	int flag = 0, i;

	for (i = 0; first[i] != '\0' || sec[i] != '\0'; i++)
	{
		if (first[i] != sec[i])
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		return (0);
	}
	return (1);
}

/**
 * _strcat - Join two string together.
 * @str1: the destination.
 * @str2: the source.
 * Return: retuns a pointer
 */
char *_strcat(char *str1, char *str2)
{
	char *p = str1 + _strlen(str1);

	while (*str2)
	{
		*p++ = *str2++;
	}
	*p = '\0';
	return (str1);
}
