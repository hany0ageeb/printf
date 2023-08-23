#include "main.h"
#include <stdlib.h>
/**
 * concate_str - concatenate two string one after the other
 * @str1: first string
 * @str2: second string
 * Return: string contain str1 followed by str2
 */
char *concate_str(const char *str1, const char *str2)
{
	unsigned int str1_len = _strlen(str1);
	unsigned int str2_len = _strlen(str2);
	unsigned int i, j;
	char *str = malloc(sizeof(char) * (str1_len + str2_len + 1));

	if (str != NULL)
	{
		i = 0;
		for (j = 0; j < str1_len; ++j, ++i)
		{
			str[i] = str1[j];
		}
		for (j = 0; j < str2_len; ++j, ++i)
		{
			str[i] = str2[j];
		}
		str[i] = '\0';
	}
	return (str);
}

