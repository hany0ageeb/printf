#include "main.h"
#include <stdarg.h>
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
			if (spec == 'x' && (*formatted_value)[0] != '0')
				_prepend(formatted_value, len, "0x", 2);
			else if (spec == 'X' && (*formatted_value)[0] != '0')
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
	}
	else
	{
		if (spec == 'd' || spec == 'i')
			value = va_arg(argptr, int);
	}
	return (value);
}
/**
 * handle_len_mode_u - handle len mod u,o,x,X
 * @len_mod: length modifier
 * @spec: spec
 * @argptr: argptr
 * Return: value
 */
size_t handle_len_mode_u(const char len_mod, const char spec, va_list argptr)
{
	size_t value;

	if (len_mod == 'l')
	{
		if (spec == 'u' || spec == 'o' || spec == 'X' || spec == 'x')
			value = va_arg(argptr, size_t);
	}
	else if (len_mod == 'h')
	{
		if (spec == 'u' || spec == 'o' || spec == 'x' || spec == 'X')
			value = va_arg(argptr, size_t);
	}
	return (value);
}
/**
 * handle_percision - handle percision
 * @formatted_value: formatted value
 * @len: formatted_value length
 * @percision: percision
 * Return: void
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
 * handle_width - handle width modifier
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
			pspec->specifier == 'x' || pspec->specifier == 'X' ||
			pspec->specifier == 'p')
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

