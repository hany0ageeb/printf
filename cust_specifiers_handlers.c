#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
/**
 * handle_b_specifier - handle custom specifier b
 * @spec: conversion specification
 * @argptr: variable arguments
 * Return: formatted value
 */
char *handle_b_specifier(const conversion_specification_t *spec,
		va_list argptr)
{
	unsigned int value, value_len;
	char *formatted_value = NULL;

	if (spec != NULL && spec->conversion_specifier == 'b')
	{
		value = va_arg(argptr, unsigned int);
		value_len = int_length(value, binary);
		formatted_value = convert_int_to_str(value, value_len, binary);
	}
	return (formatted_value);
}
/**
 * calc_len_for_S_spec - calc the length that will be taken
 * @temp: string
 * Return: length require to transform temp
 */
unsigned int calc_len_for_S_spec(const char *temp)
{
	unsigned int len = 0, i;

	if (temp != NULL)
	{
		i = 0;
		while (temp[i] != '\0')
		{
			if ((temp[i] > 0 && temp[i] < 32) || temp[i] >= 127)
			{
				len += 4;
			}
			else
			{
				len++;
			}
			i++;
		}
	}
	return (len);
}
/*
 * handle_S_specifier - handle custom specifier S
 * @spec: spec
 * @argptr: var args
 * Return: formatted value
 */
char *handle_S_specifier(const conversion_specification_t *spec,
		va_list argptr)
{
	unsigned int len = 0, code_len = 0, i, j;
	char *temp = NULL, *formatted_value = NULL, *code = NULL;

	if (spec != NULL && spec->conversion_specifier == 'S')
	{
		temp = va_arg(argptr, char *);
		len = calc_len_for_S_spec(temp);
		if (len > 0)
		{
			formatted_value = malloc(sizeof(char) * (len + 1));
			for (i = 0, j = 0; i < len && temp[j] != '\0'; j++)
			{
				if ((temp[j] > 0 && temp[j] < 32) || temp[j] >= 127)
				{
					formatted_value[i] = '\\';
					formatted_value[i + 1] = 'x';
					code = convert_int_to_str(temp[j], int_length(temp[j],
								hexadecimal), hexadecimal);
					code_len = _strlen(code);
					if (code_len == 2)
					{
						formatted_value[i] = code[0];
						formatted_value[i + 1] = code[1];
					}
					else
					{
						formatted_value[i] = '0';
						formatted_value[i + 1] = code[0];
					}
					i += 4;
				}
				else
				{
					formatted_value[i] = temp[j];
					i++;
				}
			}
		}
	}
	return (formatted_value);
}
/*
 * handle_r_specifier - handle custom r specifier
 * @spec: spec
 * @argptr: var args
 * Return: formatted value
 */

char *handle_r_specifier(const conversion_specification_t *spec,
		va_list argptr)
{
	char *formatted_value = NULL, *temp = NULL;

	if (spec != NULL && spec->conversion_specifier == 'r')
	{
		temp = va_arg(argptr, char *);
		formatted_value = copy_str(temp, _strlen(temp));
		reverse_str(formatted_value);
	}
	return (formatted_value);
}

