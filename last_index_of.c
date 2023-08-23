#include "main.h"
/**
 * last_index_of - get last index in str that has any of sch char
 * @str: string to search within
 * @l: start search at this inddex
 * @h: and end here
 * @sch: search for any of those chars
 * Return: -1 or index
 */
int last_index_of(const char *str, unsigned int l,
		unsigned int h, const char *sch)
{
	int j;

	if ((h < l && str == NULL) || sch == NULL)
		return (-1);
	while (h >= l && str[h] != '\0')
	{
		for (j = 0; sch[j] != '\0'; ++j)
		{
			if (str[h] == sch[j])
				return (h);
		}
		h--;
	}
	return (-1);
}

