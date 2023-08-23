#include "main.h"
#include <stdlib.h>
/**
 * pad_left - padd src with pad char from left to width.
 * @src: source string
 * @width: required length
 * @pad: padding char
 * Return: padded src to width
 */
char *pad_left(const char *src, long int width, const char pad)
{
	long int len = (long int)_strlen(src);
	char *str_padded = NULL;
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
			for (i = 0; i < (width - len); ++i)
			{
				str_padded[i] = pad;
			}
			for (j = 0; j < len && i < width; ++i, ++j)
			{
				str_padded[i] = src[j];
			}
			str_padded[width] = '\0';
		}
	}
	return (str_padded);
}

