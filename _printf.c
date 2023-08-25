#include "main.h"
#include <stdlib.h>
/**
 * get_width - get width
 * @format: format string
 * @start: start index
 * @end: end index
 * Return: width value or 0
 */
int get_width(const char *format, int *start, int end)
{
	int i = *start, width = 0;

	if (*start > end || format == NULL || *format == '\0')
		return (0);
	while (i <= end && format[i] != '\0' && format[i] >= '0' && format[i] <= '9')
		i++;
	width = str_to_int(format, *start, i - 1, decimal);
	*start = i;
	return (width);
}
/**
 * get_percision - get percision
 * @format: format string
 * @pl: from index
 * @h: to index
 * Return: percision or -1
 */
int get_percision(const char *format, int *pl, int h)
{
	int i, percision;

	if (format == NULL || *format == '\0' || h < *pl)
		return (-1);
	if (format[*pl] == '.')
	{
		i = (*pl) + 1;
		while (format[i] >= '0' && format[i] <= '9' && i <= h && format[i] != '\0')
			i++;
		if ((*pl + 1) == i)
		{
			*pl = i;
			return (0);
		}
		percision = str_to_int(format, (*pl) + 1, i - 1, decimal);
		*pl = i;
		return (percision);
	}
	else
	{
		return (-1);
	}
}
/**
 * tokenize - extract conversion specifier from format
 * @spec: conversion specification
 * @format: format string
 * @format_len: format string length
 * @start: start index
 * Return: end index
 */
int tokenize(conv_spec_t **spec, const char *format,
		const int format_len, int start)
{
	int end, flag_end;

	end = index_of(format, start + 1, format_len - 1, CONVERSION_SPECIFIERS);
	if (end != -1)
	{
		if (*spec == NULL)
			*spec = malloc(sizeof(conv_spec_t));
		if (*spec != NULL)
		{
			(*spec)->specifier = format[end];
			flag_end = last_index_of(format, start + 1, end - 1, CONVERSION_FLAGS);
			if (flag_end != -1)
			{
				(*spec)->flag = sub_str(format, start + 1, flag_end);
				if (is_valid_flag((*spec)->flag) == TRUE)
					flag_end++;
				else
					return (-1);
			}
			else
				flag_end = start + 1;
			(*spec)->width = get_width(format, &flag_end, end - 1);
			(*spec)->percision = get_percision(format, &flag_end, end - 1);
			if (flag_end < end && (format[flag_end] == 'l' || format[flag_end] == 'h'))
			{
				(*spec)->len_mod = format[flag_end];
				flag_end++;
			}
			if (end != flag_end)
			{
				(*spec)->formatter = NULL;
				return (-1);
			}
			else
				set_conv_spec_formatter(*spec);
		}
	}
	return (end);
}
/**
 * is_valid_flag - check if flag is valid
 * @flag: flag string
 * Return: 1 if valid 0 otherwise
 */
int is_valid_flag(const char *flag)
{
	int i;

	if (flag == NULL || *flag == '\0')
		return (TRUE);
	i = 0;
	while (flag[i] != '\0')
	{
		if (contains_char(CONVERSION_FLAGS, flag[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
/**
 * _printf - cheap clone of printf function
 * @format: format string
 * Return: number of printed chars
 */
int _printf(const char *format, ...)
{
	int count = 0, i, format_len, end;
	conv_spec_t *pspec = NULL;
	char *data = NULL;
	static char buffer[BUFF_SIZE + 1];
	static int buff_init = FALSE;
	va_list argptr;

	if (format == NULL)
		return (-1);
	if (buff_init == FALSE)
	{
		buffer[0] = '\0';
		buff_init = TRUE;
	}
	format_len = _strlen(format);
	va_start(argptr, format);
	for (i = 0; i < format_len; ++i)
	{
		if (format[i] == '%')
		{
			end = tokenize(&pspec, format, format_len, i);
			if (end == -1)
				count += _write_char(buffer, format[i], BUFF_SIZE);
			else
			{
				if (pspec != NULL && pspec->formatter != NULL)
				{
					data = pspec->formatter(pspec, argptr);
					count += _write_str(buffer, data, BUFF_SIZE);
					i = end;
				}
			}
		}
		else
			count += _write_char(buffer, format[i], BUFF_SIZE);
	}
	free_conv_spec(pspec);
	count += _flush(buffer);
	va_end(argptr);
	return (count);
}

