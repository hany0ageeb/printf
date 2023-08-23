#include "main.h"

/**
 * _to_upper - a function to change char to upper case.
 * @str: a string
 * Return: void
 */
void _to_upper(char *str)
{
	if (str != NULL)
	{
		while (*str != '\0')
		{
			if (*str >= 'a' && *str <= 'z')
			{
				*str = *str - 32;
			}
			str++;
		}
	}
}

