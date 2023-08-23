#include "main.h"
#include <stdlib.h>
/**
 * pad_right - pad a string from right with pad until width
 * @src: string to pad
 * @width: until width
 * @pad: pad char
 * Return: src padded from rigth until width
 */
char *pad_right(const char *src, long int width, const char pad)
{
	char *str_padded = NULL;
	long int len = _strlen(src);
	int i, j;

	if (len >= width)
	{
		str_padded = copy_str(src, len);
	}
	else
	{
		str_padded = malloc(sizeof(char) * (width + 1));
		if (str_padded != NULL)
		{
			for (i = width - 1; i >= len; --i)
			{
				str_padded[i] = pad;
			}
			for (j = len - 1; j >= 0 && i >= 0; --i, --j)
			{
				str_padded[i] = src[j];
			}
			str_padded[width] = '\0';
		}
	}
	return (str_padded);
}

