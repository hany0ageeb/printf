#include "main.h"
#include <stdlib.h>
/**
 * _str - construct a len string wit c repeated
 * @c: char
 * @len: string length
 * Return: string with length = len
 */
char *_str(const char c, int len)
{
	char *str = NULL;

	if (len > 0)
	{
		str = malloc(sizeof(char) * (len + 1));
		if (str != NULL)
		{
			str[len] = '\0';
			len--;
			while (len >= 0)
			{
				str[len] = c;
				len--;
			}
		}
	}
	return (str);
}
/**
 * copy_str - create a copy from src
 * @src: a string to copy
 * Return: string
 */
char *copy_str(const char *src)
{
	char *str = NULL;
	int len, i;

	if (src != NULL)
	{
		len = _strlen(src);
		str = malloc(sizeof(char) * (len + 1));
		if (str != NULL)
		{
			for (i = 0; i < len; ++i)
				str[i] = src[i];
			str[len] = '\0';
		}
	}
	return (str);
}
/**
 * _strlen - calc string length
 * @str: string
 * Return: str length without null terninatb
 */
int _strlen(const char *str)
{
	int len = 0;

	if (str == NULL)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}
/**
 * sub_str - sub string str from [start - end]
 * @str: string
 * @start: start
 * @end: end
 * Return: str from start to end
 */
char *sub_str(const char *str, int start, int end)
{
	int len = end - start + 1, i;
	char *substr = NULL;

	if (len > 0)
	{
		substr = malloc(sizeof(char) * (len + 1));
		if (substr != NULL)
		{
			i = 0;
			while (start <= end)
			{
				substr[i] = str[start];
				start++;
				i++;
			}
			substr[i] = '\0';
		}
	}
	return (substr);
}
/**
 * _to_upper - convert str to upper case
 * @str: string
 * Return: void
 */
void _to_upper(char *str)
{
	if (str != NULL)
	{
		while (*str != '\0')
		{
			if (*str >= 'a' && *str <= 'z')
				*str = (*str) - 32;
			str++;
		}
	}
}

