#include "main.h"
#include <stdlib.h>
/*
 * reverse_str - revers string
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
