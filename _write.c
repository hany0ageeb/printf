#include "main.h"
#include <stdlib.h>
#include <unistd.h>
/**
 * _write_str - write a string to std
 * @data: data to be written
 * @len: length of string
 * Return: char written count
 */
int _write_str(const char *data, int len)
{
	int count = 0;

	if (data != NULL)
	{
		count = write(STDOUT_FILENO, data, len);
	}
	return (count);
}
/**
 * _write_char - write a char to std
 * @c: char to be written
 * Return: 1 if c was written other wise -1
 */
int _write_char(const char c)
{
	char *str = malloc(sizeof(char) * 2);
	int count;

	if (str != NULL)
	{
		str[0] = c;
		str[1] = '\0';
	}
	count = _write_str(str, 1);
	free(str);
	return (count);
}
