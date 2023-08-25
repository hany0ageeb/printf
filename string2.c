#include "main.h"
#include <stdlib.h>
/**
 * reverse_str - reverse string
 * @str: original string to reverse
 * Return: a pointer to a newly created reversed version of str.
 */
char *reverse_str(const char *str)
{
	char *temp = NULL;
	int len, i, j;

	if (str != NULL)
	{
		len = _strlen(str);
		temp = malloc(sizeof(char) * (len + 1));
		if (temp != NULL)
		{
			for (i = 0, j = len - 1; i < len && j >= 0; ++i, --j)
				temp[j] = str[i];
		}
	}
	return (temp);
}
/**
 * cp_str - copy string
 * @str: original string to copy
 * Return: a copy of str
 */
char *cp_str(const char *str)
{
	char *temp = NULL;
	int len, i;

	if (str != NULL)
	{
		len = _strlen(str);
		temp = malloc(sizeof(char) * (len + 1));
		if (temp != NULL)
		{
			for (i = 0; i < len; i++)
				temp[i] = str[i];
			temp[i] = '\0';
		}
	}
	return (temp);
}

