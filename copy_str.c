#include "main.h"
#include <stdlib.h>
/**
 * copy_str - create a copy from src
 * @src: source string to copy
 * @len: src length
 * Return: a copy from src string
 */
char *copy_str(const char *src, unsigned int len)
{
	char *str = NULL;
	unsigned int i;

	if (len > 0)
	{
		str = malloc(sizeof(char) * (len + 1));
		if (str != NULL)
		{
			for (i = 0; i < len; i++)
			{
				str[i] = src[i];
			}
			str[len] = '\0';
		}
	}
	return (str);
}

