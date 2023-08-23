#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * handle_x_specifier - handle x (or X) specifier
 * @spec: conversion specifications
 * @argptr: var args
 * Return: formatted value
 */
char *handle_x_specifier(const conversion_specification_t *spec,
		va_list argptr)
{
	char *formatted_value = NULL, *temp = NULL;
	long int value;
	long int value_len;

	if (spec != NULL && (spec->conversion_specifier == 'x' ||
				spec->conversion_specifier == 'X'))
	{
		value = handle_length_for_unsigned(spec, argptr);
		value_len = int_length(value, hexadecimal);
		formatted_value = convert_uint_to_str(value, value_len, hexadecimal);
		if (spec->conversion_specifier == 'X')
			_to_upper(formatted_value);
		if (value > 0 && spec->flag != NULL
				&& contains_char(spec->flag, '#') == TRUE)
		{
			if (spec->conversion_specifier == 'x')
				temp = concate_str("0x", formatted_value);
			else
				temp = concate_str("0x", formatted_value);
			free(formatted_value);
			formatted_value = temp;
		}
	}
	return (formatted_value);
}
/**
 * handle_u_specifier - handle u conversion specifier
 * @spec: conversion specification
 * @argptr: variable arguments
 * Return: formatted value.
 */
char *handle_u_specifier(const conversion_specification_t *spec,
		va_list argptr)
{
	char *formatted_value = NULL;
	long int value, value_len;

	if (spec != NULL && spec->conversion_specifier == 'u')
	{

		value = handle_length_for_unsigned(spec, argptr);
		value_len = int_length(value, decimal);
		formatted_value = convert_uint_to_str(value, value_len, decimal);
	}
	return (formatted_value);
}
/**
 * handle_p_specifier - handle p conversion specifier
 * @spec: conversion specification
 * @argptr: var args
 * Return: formatted value
 */
char *handle_p_specifier(const conversion_specification_t *spec,
		va_list argptr)
{
	char *formatted_value = NULL, *temp = NULL;
	unsigned int value, value_len;

	if (spec != NULL && spec->conversion_specifier == 'p')
	{
		value = va_arg(argptr, unsigned int);
		if (value == 0)
		{
			formatted_value = malloc(sizeof(char) * 2);
			formatted_value[0] = '0';
			formatted_value[1] = '\0';
		}
		else
		{
			value_len = int_length(value, hexadecimal);
			temp = convert_int_to_str(value, value_len, hexadecimal);
			formatted_value = concate_str("0x", temp);
			free(temp);
		}
	}
	return (formatted_value);
}
/**
 * handle_o_specifier - handle o specifier
 * @spec: conversion specifications
 * @argptr: variable arguments
 * Return: formatted value
 */
char *handle_o_specifier(const conversion_specification_t *spec,
		va_list argptr)
{
	char *formatted_value = NULL, *temp = NULL;
	long int value;
	long int value_len, percision;

	if (spec != NULL && spec->conversion_specifier == 'o')
	{
		value = handle_length_for_unsigned(spec, argptr);
		value_len = (long int)int_length(value, octal);
		formatted_value = convert_int_to_str(value, value_len, octal);
		if (value == 0 && spec->percision == 0)
		{
			formatted_value[0] = '\0';
			return (formatted_value);
		}
		if (formatted_value[0] != '0' &&
				contains_char(spec->flag, '#') == TRUE)
		{
			temp = concate_str("0", formatted_value);
			free(formatted_value);
			formatted_value = temp;
		}
		percision = spec->percision == -1 ? spec->width : spec->percision;
		if (percision != -1 && percision > value_len)
		{
			if (contains_char(spec->flag, '-') == TRUE)
				temp = pad_right(formatted_value, spec->percision, ' ');
			else if (contains_char(spec->flag, '0') == TRUE)
				temp = pad_left(formatted_value, spec->percision, '0');
			else
				temp = pad_left(formatted_value, spec->percision, ' ');
			free(formatted_value);
			formatted_value = temp;
		}
	}
	return (formatted_value);
}
/**
 * handle_per_specifier - handles % conversion specifier
 * @spec: conversion specification
 * @argptr: va args
 * Return: formatted value
 */
char *handle_per_specifier(const conversion_specification_t *spec,
		__attribute__((unused))va_list argptr)
{
	char *formatted_value = NULL;

	if (spec->conversion_specifier == '%')
	{
		formatted_value = malloc(sizeof(char) * 2);
		if (formatted_value != NULL)
		{
			formatted_value[0] = '%';
			formatted_value[1] = '\0';
		}
	}
	return (formatted_value);
}

