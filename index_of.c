#include "main.h"

/**
 * index_of - function to get first index of any char in sch
 * @str: string to search
 * @sch: search string
 * @l:start search from here
 * @h: end search here
 * Return: -1 if not foudn otherwise the index
 */
int index_of(const char *str, unsigned int l, unsigned int h, const char *sch)
{
	int j;

	if (h < l || sch == NULL || str == NULL)
		return (-1);
	while (l <= h && str[l] != '\0')
	{
		for (j = 0; sch[j] != '\0'; j++)
		{
			if (str[l] == sch[j])
				return (l);
		}
		l++;
	}
	return (-1);
}

