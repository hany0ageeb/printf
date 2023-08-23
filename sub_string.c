#include "main.h"
#include <stdlib.h>
/**
 * sub_string - a function to substring src from start to end inclusive
 * @src: source string
 * @start: starting index
 * @end: ending index
 * Return: substring[start - end]
 */
char *sub_string(const char *src, unsigned int start, unsigned int end)
{
	char *str = NULL;
	unsigned int src_len = _strlen(src), len = 0, i;

	if (end < start || start > (src_len - 1))
		return (str);
	len = (end - start) + 1;
	len = len < src_len ? len : src_len;
	str = malloc(sizeof(char) * (len + 1));
	if (str != NULL)
	{
		i = 0;
		while (start <= end && start < src_len && i < len)
		{
			str[i] = src[start];
			start++;
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

