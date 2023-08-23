#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
/**
 * handle_c_specifier - a function to handle c specifier.
 * @specification: format spec
 * @argptr: va_list
 * Return: formatted Value.
 */
char *handle_c_specifier(const conversion_specification_t *specification,
		va_list argptr)
{
	char *formatted_value = NULL, *temp = NULL;
	char c;

	if (specification->conversion_specifier == 'c')
	{
		formatted_value = malloc(sizeof(char) * 2);
		c = (char)va_arg(argptr, int);
		formatted_value[0] = c;
		formatted_value[1] = '\0';
		if (specification->width > 0)
		{
			if (specification->flag != NULL
					&& contains_char(specification->flag, '-') == TRUE)
			{
				temp = pad_right(formatted_value, specification->width, ' ');
			}
			else
			{
				temp = pad_left(formatted_value, specification->width, ' ');
			}
			free(formatted_value);
			formatted_value = temp;
		}
	}
	return (formatted_value);
}
/**
 * handle_s_specifier - handle s conversion specifier
 * @specification: conversion specifier
 * @argptr: var arguments
 * Return: formatted value
 */
char *handle_s_specifier(const conversion_specification_t *specification,
		va_list argptr)
{
	char *formatted_value = NULL, *temp = NULL;

	if (specification->conversion_specifier == 's')
	{
		temp = va_arg(argptr, char *);
		if (specification->width > 0)
		{
			if (specification->flag != NULL
					&& contains_char(specification->flag, '-') == TRUE)
			{
				formatted_value = pad_right(temp, specification->width, ' ');
			}
			else
			{
				formatted_value = pad_left(temp, specification->width, ' ');
			}
		}
		else
		{
			formatted_value = copy_str(temp, _strlen(temp));
		}
	}
	return (formatted_value);
}
/**
 * handle_width_for_d_i_spec - handle width & percision for d_i specifier
 * @d: nmber
 * @temp: d as string
 * @percision: percision
 * @width: width
 * @flag: flags
 * Return: formatted value
 */
char *handle_width_for_d_i_spec(long int d, char *temp,
		int width, int percision, char *flag)
{
	char *formatted_value = NULL;
	int len = (int)_strlen(temp);

	if (percision != -1 && len < percision)
	{
		if (d >= 0)
			formatted_value = pad_left(temp, percision, '0');
		else
		{
			temp[0] = '0';
			formatted_value = pad_left(temp, percision, '0');
			formatted_value[0] = '-';
		}
	}
	else if (width > len)
	{
		if (flag == NULL || *flag == '\0')
			formatted_value = pad_left(temp, width, ' ');
		else if (contains_char(flag, '-') == TRUE)
			formatted_value = pad_right(temp, width, ' ');
		else if (contains_char(flag, '0') == TRUE)
		{
			if (d >= 0)
				formatted_value = pad_left(temp, width, '0');
			else
			{
				temp[0] = '0';
				formatted_value = pad_left(temp, width, '0');
				formatted_value[0] = '-';
			}
		}
		else
			formatted_value = pad_left(temp, width, ' ');

	}
	else
		formatted_value = copy_str(temp, _strlen(temp));
	return (formatted_value);
}
/**
 * handle_flag_for_d_spec - handle flag for d, i specifiers
 * @d: number
 * @temp: number as string
 * @flag: flag
 * Return: formatted value
 */
char *handle_flag_for_d_spec(long int d, char *temp, const char *flag)
{
	char *formatted_value = NULL;

	if (flag != NULL && contains_char(flag, '+') && d >= 0)
	{
		if (temp[0] == '0' || temp[0] == ' ')
		{
			temp[0] = '+';
		}
		else
		{
			formatted_value = concate_str("+", temp);
			free(temp);
			temp = formatted_value;
		}
	}
	else if (flag != NULL && contains_char(flag, ' ') && d >= 0)
	{
		if (temp[0] == '0')
		{
			temp[0] = '+';
		}
		else
		{
			formatted_value = concate_str(" ", temp);
			free(temp);
			temp = formatted_value;
		}
	}
	return (temp);
}
/**
 * handle_d_i_specifier - handle d, i specifiers
 * @spec: specification of conversion
 * @argptr: arguments
 * Return: formatted value
 */
char *handle_d_i_specifier(const conversion_specification_t *spec,
		va_list argptr)
{
	char *formatted_value = NULL, *temp = NULL;
	signed long int d, len;
	char sp = spec != NULL ? spec->conversion_specifier : 'Z';

	if (sp == 'd' || sp == 'i')
	{
		d = handle_len_mod_for_signed(spec, argptr);
		if (d == 0 && spec->percision == 0)
		{
			formatted_value = malloc(sizeof(char) * 1);
			formatted_value[0] = '\0';
			return (formatted_value);
		}
		len = (int)int_length(d, decimal);
		temp = convert_int_to_str(d, len, decimal);
		formatted_value = handle_width_for_d_i_spec(d, temp, spec->width,
				spec->percision, spec->flag);
		free(temp);
		temp = handle_flag_for_d_spec(d, formatted_value, spec->flag);
		if (temp != formatted_value)
			free(formatted_value);
		formatted_value = temp;
	}
	return (formatted_value);
}

