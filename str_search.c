#include "main.h"
/**
 * index_of -  find the first char in str that is within search string
 * @str: a string to search
 * @start: search beginf here
 * @end: and ends here
 * @search: chars to found
 * Return: first index or or -1
 */
int index_of(const char *str, int start, int end, const char *search)
{
	int j;

	if (str == NULL || search == NULL || *search == '\0')
		return (-1);
	while (str[start] != '\0' && start <= end)
	{
		j = 0;
		while (search[j] != '\0')
		{
			if (str[start] == search[j])
				return (start);
			j++;
		}
		start++;
	}
	return (-1);
}
/**
 * last_index_of - find last index
 * @str: string
 * @start: start
 * @end: end
 * @srch: Search
 * Return: index or -1 if not found
 */
int last_index_of(const char *str, int start, int end, const char *srch)
{
	int j;

	if (str == NULL || srch == NULL || *srch == '\0')
		return (-1);
	while (end >= start && end >= 0)
	{
		j = 0;
		while (srch[j] != '\0')
		{
			if (str[end] == srch[j])
				return (end);
			j++;
		}
		end--;
	}
	return (-1);
}
/**
 * contains_char - checks if str contains c
 * @str: string to search witinh
 * @c: search for this char
 * Return: 1 if found otherwise 0
 */
int contains_char(const char *str, const char c)
{
	int i;

	if (str == NULL || *str == '\0')
		return (FALSE);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

