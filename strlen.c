#include "main.h"

/**
 * _strlen - a function to calc string length.
 * @str: string
 * Return: str length or 0 if str is NULL
 */
unsigned int _strlen(const char *str)
{
	unsigned int len = 0;

	if (str == NULL)
		return (len);
	while (*str != '\0')
	{
		str++;
		len++;
	}
	return (len);
}

