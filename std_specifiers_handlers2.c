#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
/**
 * _prepend - prepend app in front of str
 * @str: string
 * @str_len: str length
 * @app: string
 * @app_len: app length
 * Return: void
 */
void _prepend(char **str, const int str_len, const char *app,
		const int app_len)
{
	char *temp;
	int i, j;

	if (str != NULL)
	{
		temp = malloc(sizeof(char) * (str_len + app_len + 1));
		if (temp != NULL)
		{
			for (i = 0; i < app_len; ++i)
				temp[i] = app[i];
			for (j = 0; j < str_len; ++j, ++i)
				temp[i] = (*str)[j];
			temp[i] = '\0';
			free(*str);
			*str = temp;
		}
	}
}
/**
 * handle_flag - handle flag
 * @formatted_value: string
 * @flag: flag
 * @spec: specifier
 * Return: void
 */
void handle_flag(char **formatted_value, const char *flag, const char spec)
{
	int len = _strlen(*formatted_value);

	if (*formatted_value != NULL)
	{
		if (contains_char(flag, '#') == TRUE)
		{
			if (spec == 'x')
				_prepend(formatted_value, len, "0x", 2);
			else if (spec == 'X')
				_prepend(formatted_value, len, "0X", 2);
			else if (spec == 'o' && (*formatted_value)[0] != '0')
				_prepend(formatted_value, len, "0", 1);
		}
		if (contains_char(flag, '+') && (*formatted_value)[0] != '-')
		{
			if (spec == 'd' || spec == 'i')
				_prepend(formatted_value, len, "+", 1);
		}
		else if (contains_char(flag, ' ') && (*formatted_value)[0] != '-')
		{
			if (spec == 'd' || spec == 'i')
				_prepend(formatted_value, len, " ", 1);
		}
	}
}
/**
 * handle_p_spec - handle p conv specifier
 * @pspec: spec con
 * @argptr: var args
 * Return: formatted value
 */
char *handle_p_spec(const conv_spec_t *pspec, va_list argptr)
{
	unsigned long int value;
	char *temp, *formatted_value;
	int i, j;

	if (pspec != NULL && pspec->specifier == 'p')
	{
		value = (unsigned long int)va_arg(argptr, void *);
		if (value == 0)
		{
			formatted_value = malloc(sizeof(char) * 2);
			formatted_value[0] = '0';
			formatted_value[1] = '\0';
		}
		else
		{
			temp = int_to_str((long int)value, hexadecimal);
			formatted_value = malloc(sizeof(char) * (_strlen(temp) + 3));
			formatted_value[0] = '0';
			formatted_value[1] = 'x';
			for (i = 2, j = 0; temp[j] != '\0'; ++j, ++i)
				formatted_value[i] = temp[j];
			formatted_value[i] = '\0';
			free(temp);
		}
	}
	return (formatted_value);
}

