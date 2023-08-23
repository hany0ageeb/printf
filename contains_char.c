#include "main.h"
/**
 * contains_char - check if string contains a char
 * @str: string to search
 * @c: char to search for
 * Return: 1 if foudn 0 otherwise
 */
int contains_char(const char *str, const char c)
{
	if (str == NULL)
		return (FALSE);
	while (*str != '\0')
	{
		if (*str == c)
			return (TRUE);
		str++;
	}
	return (FALSE);
}

