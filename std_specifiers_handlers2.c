#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
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
 * handle_len_mod - handle len modifier
 * @len_mod: len mod
 * @spec: spec
 * @argptr: var args
 * Return: value
 */
long int handle_len_mod(const char len_mod, const char spec, va_list argptr)
{
	long int value;

	if (len_mod == 'l')
	{
		if (spec == 'd' || spec == 'i')
			value = va_arg(argptr, long int);
		else if (spec == 'u' || spec == 'o' || spec == 'x' || spec == 'X')
			value = va_arg(argptr, unsigned long int);
	}
	else
	{
		if (spec == 'd' || spec == 'i')
			value = va_arg(argptr, int);
		else if (spec == 'u' || spec == 'o' || spec == 'x' || spec == 'X')
			value = va_arg(argptr, unsigned int);
	}
	return (value);
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
/**
 * handle_percision - handle percision
 * @formatted_value: formatted value
 * @value: value
 * @percision: percision
 */
void handle_percision(char **formatted_value, const int len,
		const int percision)
{
	char sign;

	if (percision != -1)
	{
		if (percision == 0)
		{
			if ((len == 1 && (*formatted_value)[0] == '0') ||
					(len == 2 && (*formatted_value)[1] == '0'))
				(*formatted_value)[0] = '\0';
		}
		else
		{
			if (len < percision)
			{
				if ((*formatted_value)[0] == '-' || (*formatted_value)[0] == '+')
				{
					sign = (*formatted_value)[0];
					(*formatted_value)[0] = '0';
					pad_left(formatted_value, len, percision, '0');
					(*formatted_value)[0] = sign;
				}
				else
				{
					pad_left(formatted_value, len, percision, '0');
				}
			}
		}
	}
}
/**
 * handle_width: handle width modifier
 * @formatted_value: formatted value
 * @pspec: conv specifications
 * Return: void
 */
void handle_width(char **formatted_value, const conv_spec_t *pspec)
{
	int len;
	char sign;

	if (formatted_value == NULL)
		return;
	len = _strlen(*formatted_value);
	if ((pspec->specifier == 'c' || pspec->specifier == 's')
			&& len < pspec->width)
	{
		if (contains_char(pspec->flag, '-'))
			pad_right(formatted_value, len, pspec->width, ' ');
		else
			pad_left(formatted_value, len, pspec->width, ' ');
	}
	else if (pspec->specifier == 'd' || pspec->specifier == 'i' ||
			pspec->specifier == 'u' || pspec->specifier == 'o' ||
			pspec->specifier == 'x' || pspec->specifier == 'X')
	{
		handle_percision(formatted_value, len, pspec->percision);
		len = _strlen(*formatted_value);
		if (len >= pspec->width)
			return;
		if (contains_char(pspec->flag, '-'))
			if ((*formatted_value)[0] == '-' || (*formatted_value)[0] == '+')
			{
				sign = (*formatted_value)[0];
				(*formatted_value)[0] = ' ';
				pad_right(formatted_value, len, pspec->width, ' ');
				(*formatted_value)[0] = sign;
			}
			else
				pad_right(formatted_value, len, pspec->width, ' ');
		else
			if (contains_char(pspec->flag, '0') && pspec->percision == -1)
				pad_left(formatted_value, len, pspec->width, '0');
			else
				pad_left(formatted_value, len, pspec->width, ' ');
	}
}

